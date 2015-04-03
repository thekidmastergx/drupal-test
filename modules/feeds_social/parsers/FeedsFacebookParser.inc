<?php
// $Id: FeedsFacebookParser.inc,v 1.1 2011/01/24 22:46:37 serbanghita Exp $

/**
* Parses Facebook Links Feed
* eg. http://www.facebook.com/feeds/share_posts.php?id=1133615313&viewer=1282112668&key=9363a00ee5&format=rss20
* 
*/
class FeedsFacebookParser extends FeedsParser {

  /**
  * Parses a raw string and populates FeedsImportBatch object from it.
  */
  public function parse(FeedsImportBatch $batch, FeedsSource $source) {
    // Get the file's content.
    $string = $batch->getRaw();

    // Parse it...
    // The parsed result should be an array of arrays of field name => value.
    //http://drupal.org/node/199337
    $xml = simplexml_load_string($string);
    
    //dsm($xml->channel->item);
    
	// $xml is an object of type SimpleXML
	//$text = $xml->asXML();
	//cache_set('tmp_facebook_feed',$text);
	
	// And later retrieve with:
	//$xml_text = cache_get('tmp_facebook_feed');
	//$xml = new SimpleXMLElement($xml_text);
	
	// And now $retrieved_object will be the same as $xmlobject    

    
    foreach($xml->channel->item as $id => $obj_entry){    	
    	
    	//dsm($obj_entry->title);
    	if( ! empty( trim( (string)$obj_entry->title ) ) ){
	    	$items[] = array(
    			'guid' 		=> (string)$obj_entry->guid,
    			'title' 	=> str_replace("&#039;","'",(string)$obj_entry->title),
    			'url'		=> (string)$obj_entry->link,    		    		
    			'body'		=> (string)$obj_entry->description,
    			'published'     => strtotime((string)$obj_entry->pubDate),
    			'author'	=> (string)$obj_entry->author
    		);
    	}
    	//break;
    	
    }

    // Populate the FeedsImportBatch object with the parsed results.
    $batch->setTitle(str_replace("&#039;","'",(string)$obj_entry->title));
    $batch->setItems($items);
  }

  public function getMappingSources() {
    return array(
      'guid' => array(
        'name' => t('GUID'),
        'description' => t('Unique ID.'),
      ),
      'title' => array(
        'name' => t('Title'),
        'description' => t('Title of the Facebook link'),
      ),  
      'url' => array(
        'name' => t('URL'),
        'description' => t('URL to the Facebook profile story'),
      ),
      'body' => array(
        'name' => t('Body'),
        'description' => t('HTML encoded description of the Facebook link'),
      ),               
      'published' => array(
        'name' => t('Date published'),
        'description' => t('Date'),
      ), 
      'author' => array(
        'name' => t('Author'),
        'description' => t('The poster of the link'),
      )                                                          
    );
  }

} 
