<?php
/**
 * @file
 * oa_matchbox.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function oa_matchbox_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'oa_matchbox';
  $page->task = 'page';
  $page->admin_title = 'Site Map';
  $page->admin_description = '';
  $page->path = 'matchbox/!node';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_oa_matchbox_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'oa_matchbox';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bee020f6-add9-400b-839e-c5fa1ec85a03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_matchbox_app';
    $pane->subtype = 'oa_matchbox_app';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'oa_matchbox_parent' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'form_build_id' => 'form-K-kNfXhLu_CkyB1h9QmmnmtRTJzLi0CyX7_OgnbkOfg',
      'form_token' => 'QirTMBeGJboHuNQ-QgckipOfF033GsybkNZsJRt6kB4',
      'form_id' => 'oa_matchbox_app_settings_form',
      'op' => 'Finish',
      'oa_matchbox_help' => 1,
      'oa_matchbox_match_help' => array(
        'value' => '<p>Open Atrium sites are divided into <strong>Matches</strong>. A Match can be a department, project, region, office, brand, working group, etc. Once a match is created, you can select it to move into that match and create more content. Select the "<strong>New Match</strong>" button to create a new match.</p>',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'oa_matchbox_section_help' => array(
        'value' => '<p>Matches contain content within "<strong>Sections</strong>". A Section can be a Calendar, Discussion Forum, Document Library, Task list, Folder, etc. Select the "<strong>New Section</strong>" button to create a new section. Matches can also be subdivided further into <strong>Sub-matches</strong>. &nbsp;Select the "<strong>New Submatch</strong>" button to create a new sub-match.</p>',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'oa_matchbox_fullpage' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
    $display->content['new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e'] = $pane;
    $display->panels['contentmain'][0] = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-9abcfdb2-c415-4ab7-8c0d-8110f83eab8e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['oa_matchbox'] = $page;

  return $pages;

}
