<?php
/**
 * @file
 * oa_dotgo.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function oa_dotgo_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_dotgo_match';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'Dotgo Match',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'dotgo_match' => 'dotgo_match',
            ),
          ),
          'context' => 'argument_node_edit_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'radix_burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '25b12fdd-d883-4d28-8872-4cc1f30091c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-45a0185a-1dd8-4615-959e-7937b8b0c253';
    $pane->panel = 'contentmain';
    $pane->type = 'node_form_title';
    $pane->subtype = 'node_form_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '45a0185a-1dd8-4615-959e-7937b8b0c253';
    $display->content['new-45a0185a-1dd8-4615-959e-7937b8b0c253'] = $pane;
    $display->panels['contentmain'][0] = 'new-45a0185a-1dd8-4615-959e-7937b8b0c253';
    $pane = new stdClass();
    $pane->pid = 'new-a948edb5-a1d6-4184-9aad-13b45b3f3583';
    $pane->panel = 'contentmain';
    $pane->type = 'form';
    $pane->subtype = 'form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a948edb5-a1d6-4184-9aad-13b45b3f3583';
    $display->content['new-a948edb5-a1d6-4184-9aad-13b45b3f3583'] = $pane;
    $display->panels['contentmain'][1] = 'new-a948edb5-a1d6-4184-9aad-13b45b3f3583';
    $pane = new stdClass();
    $pane->pid = 'new-f7f6ea84-a3ec-4394-bee0-7f5781448650';
    $pane->panel = 'sidebar';
    $pane->type = 'entity_form_field';
    $pane->subtype = 'node:group_access';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => '',
      'formatter' => '',
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f7f6ea84-a3ec-4394-bee0-7f5781448650';
    $display->content['new-f7f6ea84-a3ec-4394-bee0-7f5781448650'] = $pane;
    $display->panels['sidebar'][0] = 'new-f7f6ea84-a3ec-4394-bee0-7f5781448650';
    $pane = new stdClass();
    $pane->pid = 'new-a62d7e5d-c05f-416c-b36c-0acf7b0f5c11';
    $pane->panel = 'sidebar';
    $pane->type = 'node_form_oa_notifications';
    $pane->subtype = 'node_form_oa_notifications';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a62d7e5d-c05f-416c-b36c-0acf7b0f5c11';
    $display->content['new-a62d7e5d-c05f-416c-b36c-0acf7b0f5c11'] = $pane;
    $display->panels['sidebar'][1] = 'new-a62d7e5d-c05f-416c-b36c-0acf7b0f5c11';
    $pane = new stdClass();
    $pane->pid = 'new-83c18373-a631-4bf2-b261-deb8a29f1def';
    $pane->panel = 'sidebar';
    $pane->type = 'node_form_publishing';
    $pane->subtype = 'node_form_publishing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_node_edit_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '83c18373-a631-4bf2-b261-deb8a29f1def';
    $display->content['new-83c18373-a631-4bf2-b261-deb8a29f1def'] = $pane;
    $display->panels['sidebar'][2] = 'new-83c18373-a631-4bf2-b261-deb8a29f1def';
    $pane = new stdClass();
    $pane->pid = 'new-c9471e75-f9a5-45f6-8c5d-a217023be39c';
    $pane->panel = 'sidebar';
    $pane->type = 'node_form_author';
    $pane->subtype = 'node_form_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'c9471e75-f9a5-45f6-8c5d-a217023be39c';
    $display->content['new-c9471e75-f9a5-45f6-8c5d-a217023be39c'] = $pane;
    $display->panels['sidebar'][3] = 'new-c9471e75-f9a5-45f6-8c5d-a217023be39c';
    $pane = new stdClass();
    $pane->pid = 'new-8c7a4171-5435-463e-ae9d-a298789b3fd4';
    $pane->panel = 'sidebar';
    $pane->type = 'node_form_buttons';
    $pane->subtype = 'node_form_buttons';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(),
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '8c7a4171-5435-463e-ae9d-a298789b3fd4';
    $display->content['new-8c7a4171-5435-463e-ae9d-a298789b3fd4'] = $pane;
    $display->panels['sidebar'][4] = 'new-8c7a4171-5435-463e-ae9d-a298789b3fd4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_dotgo_match'] = $handler;

  return $export;
}
