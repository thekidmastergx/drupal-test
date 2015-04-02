<?php
// $Id: feeds_social.defaults.inc,v 1.4 2011/02/13 19:21:21 serbanghita Exp $

/**
 * @file
 * Actual function bodies for default hook definitions in
 * feeds_social.features.inc.
 */


/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _feeds_social_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _feeds_social_feeds_importer_default() {
  $export = array();
  $parsers = variable_get('feeds_social_parsers', array());

  //dpm('Enter in '.__FUNCTION__);

  if($parsers['twitter_search']['install_status']==1){

  //Twitter Importer
$feeds_importer = new stdClass;
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'feed_twitter_search';
$feeds_importer->config = array(
  'name' => 'Twitter',
  'description' => 'Import Twitter.com updates from RSS, create nodes from feed items.',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsTwitterParser',
    'config' => array(),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'content_type' => 'feed_item_twitter_search',
      'update_existing' => '2',
      'expire' => '2419200',
      'mappings' => array(
        0 => array(
          'source' => 'tweet_text',
          'target' => 'title',
          'unique' => FALSE,
        ),
        1 => array(
          'source' => 'tweet_html',
          'target' => 'body',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'published',
          'target' => 'created',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'author_name',
          'target' => 'field_twitter_author_name',
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'author_uri',
          'target' => 'field_author_link',
          'unique' => FALSE,
        ),
        5 => array(
          'source' => 'author_pic',
          'target' => 'field_author_img',
          'unique' => FALSE,
        ),
        6 => array(
          'source' => 'tweet_link',
          'target' => 'field_tweet_url',
          'unique' => FALSE,
        ),
        7 => array(
          'source' => 'guid',
          'target' => 'guid',
          'unique' => TRUE,
        ),
        8 => array(
          'source' => 'geo_point',
          'target' => 'field_twitter_geopoint',
          'unique' => FALSE,
        ),
        9 => array(
          'source' => 'place_id',
          'target' => 'field_twitter_loc_point',
          'unique' => FALSE,
        ),
        10 => array(
          'source' => 'place_fullname',
          'target' => 'field_twitter_loc_fullname',
          'unique' => FALSE,
        ),
        11 => array(
          'source' => 'place_type',
          'target' => 'field_twitter_loc_type',
          'unique' => FALSE,
        ),
        12 => array(
          'source' => 'place_source',
          'target' => 'field_twitter_source',
          'unique' => FALSE,
        ),
      ),
      'input_format' => '2',
      'author' => 0,
    ),
  ),
  'content_type' => 'feed_twitter_search',
  'update' => 0,
  'import_period' => '1800',
  'expire_period' => 3600,
  'import_on_create' => 1,
);


  $export['feed_twitter_search'] = $feeds_importer;

  }


if($parsers['facebook_links']['install_status']==1){
  
$feeds_importer = new stdClass;
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'feed_facebook_links';
$feeds_importer->config = array(
  'name' => 'Facebook',
  'description' => 'Imports Facebook.com Links from RSS, create nodes from feed items.',
  'fetcher' => array(
    'plugin_key' => 'FeedsHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsFacebookParser',
    'config' => array(),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'content_type' => 'feed_item_facebook_links',
      'update_existing' => 1,
      'expire' => '604800',
      'mappings' => array(
        '0' => array(
          'source' => 'guid',
          'target' => 'guid',
          'unique' => 1,
        ),
        '1' => array(
          'source' => 'published',
          'target' => 'created',
          'unique' => FALSE,
        ),
        '2' => array(
          'source' => 'title',
          'target' => 'title',
          'unique' => FALSE,
        ),
        '3' => array(
          'source' => 'body',
          'target' => 'body',
          'unique' => FALSE,
        ),
        '4' => array(
          'source' => 'url',
          'target' => 'field_facebook_link',
          'unique' => FALSE,
        ),
        '5' => array(
          'source' => 'author',
          'target' => 'field_facebook_author',
          'unique' => FALSE,
        ),
      ),
      'author' => 0,
    ),
  ),
  'content_type' => 'feed_facebook_links',
  'update' => 0,
  'import_period' => '1800',
  'expire_period' => 3600,
  'import_on_create' => 1,
);
  

$export['feed_facebook_links'] = $feeds_importer;
}

if($parsers['avangate_affiliate']['install_status']==1){



$feeds_importer = new stdClass;
$feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
$feeds_importer->api_version = 1;
$feeds_importer->id = 'avangate_affiliate';
$feeds_importer->config = array(
  'name' => 'Avangate Affiliate',
  'description' => 'Imports Avangate.com Affiliate Links from RSS, create nodes from feed items.',
  'fetcher' => array(
    'plugin_key' => 'FeedsCompressHTTPFetcher',
    'config' => array(
      'auto_detect_feeds' => FALSE,
      'use_pubsubhubbub' => FALSE,
      'designated_hub' => '',
    ),
  ),
  'parser' => array(
    'plugin_key' => 'FeedsAvangateAffiliateParser',
    'config' => array(),
  ),
  'processor' => array(
    'plugin_key' => 'FeedsNodeProcessor',
    'config' => array(
      'content_type' => 'feed_item_avangate_affiliate',
      'input_format' => '0',
      'update_existing' => '2',
      'expire' => '-1',
      'mappings' => array(
        0 => array(
          'source' => 'ID',
          'target' => 'guid',
          'unique' => 1,
        ),
        1 => array(
          'source' => 'Name',
          'target' => 'title',
          'unique' => FALSE,
        ),
        2 => array(
          'source' => 'LongDescription',
          'target' => 'body',
          'unique' => FALSE,
        ),
        3 => array(
          'source' => 'Category',
          'target' => 'taxonomy:'.(int)$parsers['avangate_affiliate']['vocabularies']['Category']['id'],
          'unique' => FALSE,
        ),
        4 => array(
          'source' => 'Platforms',
          'target' => 'taxonomy:'.(int)$parsers['avangate_affiliate']['vocabularies']['Platforms']['id'],
          'unique' => FALSE,
        ),
        5 => array(
          'source' => 'ShortDescription',
          'target' => 'field_product_shortdescription',
          'unique' => FALSE,
        ),
        6 => array(
          'source' => 'Version',
          'target' => 'field_product_version',
          'unique' => FALSE,
        ),
        7 => array(
          'source' => 'Currency',
          'target' => 'field_product_currency',
          'unique' => FALSE,
        ),
        8 => array(
          'source' => 'Price',
          'target' => 'field_product_price',
          'unique' => FALSE,
        ),
        9 => array(
          'source' => 'CommissionType',
          'target' => 'field_product_commissiontype',
          'unique' => FALSE,
        ),
        10 => array(
          'source' => 'Commission',
          'target' => 'field_product_commission',
          'unique' => FALSE,
        ),
        11 => array(
          'source' => 'AffiliateBuyLink',
          'target' => 'field_product_buy_url',
          'unique' => FALSE,
        ),
        12 => array(
          'source' => 'AffiliateTrialLink',
          'target' => 'field_product_trial_url',
          'unique' => FALSE,
        ),
        13 => array(
          'source' => 'Thumbnail',
          'target' => 'field_product_big_pic',
          'unique' => FALSE,
        ),
        14 => array(
          'source' => 'SmallThumbnail',
          'target' => 'field_product_small_pic',
          'unique' => FALSE,
        ),
        15 => array(
          'source' => 'PADlink',
          'target' => 'field_product_pad_url',
          'unique' => FALSE,
        ),
        16 => array(
          'source' => 'Vendor',
          'target' => 'taxonomy:'.(int)$parsers['avangate_affiliate']['vocabularies']['Vendor']['id'],
          'unique' => FALSE,
        ),
      ),
      'author' => 0,
    ),
  ),
  'content_type' => 'feed_avangate_affiliate',
  'update' => 0,
  'import_period' => '43200',
  'expire_period' => 3600,
  'import_on_create' => 1,
);


$export['feed_avangate_affiliate'] = $feeds_importer;

}

  
  return $export;
}
