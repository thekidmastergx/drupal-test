<?php
//$Id

class FeedsCompressHTTPBatch extends FeedsHTTPBatch {

  protected $url;

  /**
   * Constructor.
   */
  public function __construct($url = NULL, $feed_nid) {
      //dpm(__METHOD__);
    $this->url = $url;
    parent::__construct($url, $feed_nid);
  }

   /**
   * Implementation of FeedsImportBatch::getRaw();
   * @param $args
   *    username
   *    password
   *    accept_invalid_cert
   *    custom_headers
   */
  public function getRaw($args=array()) {
    feeds_include_library('http_request.inc', 'http_request');
    //dpm($args, '$args');
    //dpm(__METHOD__);
    $result = http_request_get($this->url, $args['username'], $args['password'], $args['accept_invalid_cert']);

    if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
      throw new Exception(t('Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $result->code)));
    }

    //dpm($result->headers, 'headers');
    //dpm($result->headers['Content-Type'], 'Content-Type');

    //Check if we go the proper zip or gzip headers.
    $compressed = false;
    if(strpos($result->headers['Content-Type'], 'application/zip')!==false ||
       strpos($result->headers['Content-Type'], 'application/octet-stream')!==false && (strpos($result->headers['Content-Type'], '.zip')!==false || strpos($this->url, '.gz')!==false)){
        $ext = 'zip';
        $compressed = true;
    }
    if(strpos($result->headers['Content-Type'], 'application/x-gzip')!==false ||
       strpos($result->headers['Content-Type'], 'application/octet-stream')!==false && (strpos($result->headers['Content-Type'], '.gz')!==false || strpos($this->url, '.gz')!==false)){
        $ext = 'gz';
        $compressed = true;
    }

    if($compressed){

        if(!function_exists('gzopen') || !function_exists('zip_open')){
            drupal_set_message('Zip encoding detected, but you dont have PHP with <strong>php_zlib</strong> or <strong>php_zip</strong> support. You file has <em>'.$ext.'</em> extension.','warning');
        } else {

            $tmp_filename_ = md5(time()).'.'.$ext;
            $fsd = file_save_data($result->data, file_directory_path().'/'.$tmp_filename_, FILE_EXISTS_REPLACE);

            if($fsd && $ext=='gz'){
                $zd = gzopen(file_directory_path().'/'.$tmp_filename_, 'r');
                while (!gzeof($zd)) {
                    $contents .= gzread($zd, 10000);
                }
                gzclose($zd);
                drupal_set_message('Gzip encoding detected. Unzipping the file.');
            }
            if($fsd && $ext=='zip'){
                $zd = zip_open(file_directory_path().'/'.$tmp_filename_);
                while ($zip_entry = zip_read($zd)) {
                    if (zip_entry_open($zd, $zip_entry)) {
                        $contents .= zip_entry_read($zip_entry, zip_entry_filesize($zip_entry));
                        zip_entry_close($zip_entry);
                    }
                }
                zip_close($zd);
                drupal_set_message('Zip encoding detected. Unzipping the file.');


            }
            //Delete the temporary file.
            @unlink(file_directory_path().'/'.$tmp_filename_);

            $result->data = trim($contents);

        }
    }
    //dpm($result->headers['Content-Type'], 'Content-Type');

    return $result->data;
  }

}

class FeedsCompressHTTPFetcher extends FeedsHTTPFetcher {
   
  /**
   * Implementation of FeedsFetcher::fetch().
   */
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    if ($this->config['use_pubsubhubbub'] && ($raw = $this->subscriber($source->feed_nid)->receive())) {
      return new FeedsImportBatch($raw, $source->feed_nid);
    }
    //dpm(__METHOD__);
    //dpm($source->feed_nid, 'feed_nid');
    //dpm($source_config['source'], 'source');
    return new FeedsCompressHTTPBatch($source_config['source'], $source->feed_nid);
  }

}
?>