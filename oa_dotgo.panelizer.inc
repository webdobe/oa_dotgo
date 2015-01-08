<?php
/**
 * @file
 * oa_dotgo.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function oa_dotgo_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:dotgo_match:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'dotgo_match';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_oa_pane',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '9ca515a2-1ad3-434c-b55d-062f412162fe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1c705557-ed9c-4e0d-9dcf-637f155e4be1';
    $pane->panel = 'contentmain';
    $pane->type = 'oa_matchbox_app';
    $pane->subtype = 'oa_matchbox_app';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'oa_matchbox_parent' => 0,
      'oa_matchbox_help' => 1,
      'oa_matchbox_fullpage' => 1,
      'oa_matchbox_match_help' => array(
        'value' => '',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'oa_matchbox_section_help' => array(
        'value' => '',
        'format' => 'panopoly_wysiwyg_text',
      ),
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'form_build_id' => 'form-XQoj4N3GXuNhF4pc3xbNrIeWBAR-_GJQgjr1NJbmZes',
      'form_token' => 'IURtRXvzyJNAwyiLYQvpurM73m51Jqd_6Vi2lalNLlY',
      'form_id' => 'oa_matchbox_app_settings_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1c705557-ed9c-4e0d-9dcf-637f155e4be1';
    $display->content['new-1c705557-ed9c-4e0d-9dcf-637f155e4be1'] = $pane;
    $display->panels['contentmain'][0] = 'new-1c705557-ed9c-4e0d-9dcf-637f155e4be1';
    $pane = new stdClass();
    $pane->pid = 'new-31fec095-1656-45b9-b553-49d5105bbf6f';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '0',
      'comments_per_page' => '10',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Messages',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '31fec095-1656-45b9-b553-49d5105bbf6f';
    $display->content['new-31fec095-1656-45b9-b553-49d5105bbf6f'] = $pane;
    $display->panels['contentmain'][1] = 'new-31fec095-1656-45b9-b553-49d5105bbf6f';
    $pane = new stdClass();
    $pane->pid = 'new-603dfb87-bc3c-4b83-b767-7be4c381726d';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => 'Send a Message',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '603dfb87-bc3c-4b83-b767-7be4c381726d';
    $display->content['new-603dfb87-bc3c-4b83-b767-7be4c381726d'] = $pane;
    $display->panels['contentmain'][2] = 'new-603dfb87-bc3c-4b83-b767-7be4c381726d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:dotgo_match:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:oa_section:oa_section_dotgo';
  $panelizer->title = 'Dotgo Section';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'oa_section';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'radix_bryant_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
    'sidebar' => array(
      'style' => 'oa_styles_oa_pane',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'affb0a00-4608-4cef-94ca-b3147c959f46';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda';
    $pane->panel = 'contentmain';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9d3303b-f59f-4e65-bcd7-67a42b55cdda';
    $display->content['new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda'] = $pane;
    $display->panels['contentmain'][0] = 'new-d9d3303b-f59f-4e65-bcd7-67a42b55cdda';
    $pane = new stdClass();
    $pane->pid = 'new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
    $pane->panel = 'contentmain';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
    $display->content['new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc'] = $pane;
    $display->panels['contentmain'][1] = 'new-da9053d3-c4a2-4bb4-a0d0-9e66b49efabc';
    $pane = new stdClass();
    $pane->pid = 'new-f10f431a-4696-457f-ac52-43a588d29a6e';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_dotgo_match-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '10',
      'offset' => '0',
      'fields_override' => array(
        'nid' => 0,
        'title' => 1,
        'field_dotgo_match_pattern' => 1,
        'edit_node' => 1,
        'clone_node' => 1,
        'delete_node' => 1,
      ),
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => '',
      'override_title_text' => '',
      'view_settings' => 'table',
      'header_type' => 'titles',
      'view_mode' => 'teaser',
      'widget_title' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f10f431a-4696-457f-ac52-43a588d29a6e';
    $display->content['new-f10f431a-4696-457f-ac52-43a588d29a6e'] = $pane;
    $display->panels['contentmain'][2] = 'new-f10f431a-4696-457f-ac52-43a588d29a6e';
    $pane = new stdClass();
    $pane->pid = 'new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'oa_recent_activity-section_activity';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'exposed' => array(
        'type' => array(),
        'realname' => '',
        'og_group_ref_target_id' => '',
        'og_group_ref_target_id_mine' => 0,
        'og_subspaces_view_all' => 0,
        'oa_section_ref_target_id' => '',
        'use_pager' => 1,
        'pager_id' => '1',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'show_exposed_form' => 0,
      'items_per_page' => '20',
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $display->content['new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d'] = $pane;
    $display->panels['contentmain'][3] = 'new-bb4d24a8-400f-4710-8ed8-4617dcb6a89d';
    $pane = new stdClass();
    $pane->pid = 'new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
    $pane->panel = 'sidebar';
    $pane->type = 'oa_widgets_content_visibility';
    $pane->subtype = 'oa_widgets_content_visibility';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'return' => 'Finish',
      'cancel' => 'Cancel',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '',
      'form_build_id' => 'form-V0GNaOe_jcI4GeEbCDAJvWABqI8dLL3oQc2wt_JoNqk',
      'form_token' => 'njVkGwxcnRn82ge96ivsc_xCRz5OGZPGwWJyd994lQM',
      'form_id' => 'oa_widgets_content_visibility_edit_form',
      'op' => 'Finish',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
    $display->content['new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f'] = $pane;
    $display->panels['sidebar'][0] = 'new-f2dfa2bb-79a3-4e2e-89b9-d6d048e6846f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:oa_section:oa_section_dotgo'] = $panelizer;

  return $export;
}
