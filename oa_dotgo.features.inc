<?php
/**
 * @file
 * oa_dotgo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function oa_dotgo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function oa_dotgo_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_oa_wizard().
 */
function oa_dotgo_default_oa_wizard() {
  $items = array();
  $items['match_wizard'] = entity_import('oa_wizard', '{
    "bundle" : "wizard",
    "language" : "und",
    "name" : "match_wizard",
    "title" : "Match Wizard",
    "created" : "0",
    "changed" : "0",
    "data" : null,
    "field_wizard_steps" : { "und" : [
        {
          "value" : "title: Name | fields: [title]\\r\\ntitle: Type | fields: [field_dotgo_match_type]\\r\\ntitle: Match | fields: [field_dotgo_match_pattern,field_dotgo_match_message,field_dotgo_match_engine,field_dotgo_match_webform]",
          "format" : null,
          "safe_value" : "title: Name | fields: [title]\\r\\ntitle: Type | fields: [field_dotgo_match_type]\\r\\ntitle: Match | fields: [field_dotgo_match_pattern,field_dotgo_match_message,field_dotgo_match_engine,field_dotgo_match_webform]"
        }
      ]
    },
    "field_wizard_type" : { "und" : [ { "value" : "dotgo_match" } ] }
  }');
  return $items;
}
