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
}
