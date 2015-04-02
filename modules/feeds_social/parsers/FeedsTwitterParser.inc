<?php
// $Id: FeedsTwitterParser.inc,v 1.2 2011/02/13 19:21:21 serbanghita Exp $

require_once(dirname(__FILE__) .'/../feeds_social.install');

/**
* Parses the Twitter search feed eg. http://search.twitter.com/search.atom?q=world cup
* and maps it the fields of the feed_item_twitter node type.
*/
class FeedsTwitterParser extends FeedsParser {

  /**
  * Parses a raw string and populates FeedsImportBatch object from it.
  */
  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
    // Get the file's content.
    $string = $batch->getRaw();

    // Parse it...
    // The parsed result should be an array of arrays of field name => value.
    $xml = simplexml_load_string($string);
    // Register namespaces.
    // Load this for extracting geolocation info.
    $arr_namespaces = $xml->getDocNamespaces();
    //dpm($arr_namespaces);
    
    foreach($xml->entry as $id => $obj_entry){
    	
    	$tmp_link[0] = (array)$obj_entry->link[0]['href'];
    	$tmp_link[1] = (array)$obj_entry->link[1]['href'];
        $tmp_place = $obj_entry->children($arr_namespaces['twitter']);
        //dpm((string)$tmp_place->place->id);
        //dpm((string)$tmp_place->place->full_name);
        //dpm((string)$tmp_place->place->type);
        //dpm((string)$tmp_place->source);
        $tmp_point = $tmp_place->children($arr_namespaces['georss']);
        //dpm((string)$tmp_point->point);
    	
    	$items[] = array(
    		'guid'              => (string)$obj_entry->id,
    		'published'         => strtotime((string)$obj_entry->published),
    		'tweet_link'        => $tmp_link[0],
    		'author_pic'        => $tmp_link[1],
    		'tweet_text'        => (string)$obj_entry->title,
    		'tweet_html'        => (string)$obj_entry->content,
    		'updated'           => strtotime((string)$obj_entry->updated),
    		'author_name'       => (string)$obj_entry->author->name,
    		'author_uri'        => (string)$obj_entry->author->uri,
                //geolocation
                'place_id'          => (string)$tmp_place->place->id,
                'place_fullname'    => (string)$tmp_place->place->full_name,
                'place_type'        => (string)$tmp_place->place->type,
                'place_source'      => (string)$tmp_place->source,
                'geo_point'         => (string)$tmp_point->point
    	);
    	
    	//print_r($items); 
    	//exit;
    	unset($tmp_link);
    }
    //return false;

    // Populate the FeedsImportBatch object with the parsed results.
    $batch->setTitle($obj_entry->title);
    $batch->setItems($items);
  }

  public function getMappingSources() {
    return array(
      'guid' => array(
        'name' => t('GUID'),
        'description' => t('Unique ID.'),
      ),
      'published' => array(
        'name' => t('Date published'),
        'description' => t('Date when the tweet was published.'),
      ),
      'tweet_link' => array(
        'name' => t('Tweet link'),
        'description' => t('Link to the original tweet.'),
      ),
      'author_pic' => array(
        'name' => t('Author\'s pic'),
        'description' => t('Tweet author\'s pic.'),
      ),
      'tweet_text' => array(
        'name' => t('Tweet (txt)'),
        'description' => t('Text version of the tweet.'),
      ),
      'tweet_html' => array(
        'name' => t('Tweet (html)'),
        'description' => t('HTML version of the tweet.'),
      ),
      'updated' => array(
        'name' => t('Date updated'),
        'description' => t('Date when the tweet was updated.'),
      ), 
      'author_name' => array(
        'name' => t('Author\'s Name'),
        'description' => t('Tweet\'s author\'s name.'),
      ),
      'author_uri' => array(
        'name' => t('Authors\' URL'),
        'description' => t('Tweet\'s author\'s URL.'),
      ),

      'geo_point'         => array('name' => t('Geo Point'), 'description' => t('')),
      'place_id'          => array('name' => t('Location Id'), 'description' => t('')),
      'place_fullname'    => array('name' => t('Location Name'), 'description' => t('')),
      'place_type'        => array('name' => t('Location Type'), 'description' => t('')),
      'place_source'      => array('name' => t('Tweet Source'), 'description' => t('')),
      

    );
  }

} 