<?php
// $Id: feeds_social.features.inc,v 1.1 2010/08/02 17:38:14 serbanghita Exp $

/**
 * @file
 * Default hook definitions.
 */

/**
 * Implementation of hook_ctools_plugin_api().
 */
function feeds_social_ctools_plugin_api() {
  module_load_include('inc', 'feeds_social', 'feeds_social.defaults');
  $args = func_get_args();
  return call_user_func_array('_feeds_social_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function feeds_social_feeds_importer_default() {
  module_load_include('inc', 'feeds_social', 'feeds_social.defaults');
  $args = func_get_args();
  return call_user_func_array('_feeds_social_feeds_importer_default', $args);
}
