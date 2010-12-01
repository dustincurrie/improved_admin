<?php
// $Id$


/**
 * @file
 * Default admin view for content.
 */

/**
 * Implementation of hook_views_default_views().
 */

function improved_admin_views_default_views() {
  $views = array();
  $view = new view;
  $view->name = 'improved_admin_content';
  $view->description = 'Emulates the Drupal content administration page with enhancements';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Default', 'default');
  $handler->override_option('fields',  _improved_admin_get_content_fields());
  $handler->override_option('sorts', array(
    'changed' => array(
      'order' => 'DESC',
      'granularity' => 'second',
      'id' => 'changed',
      'table' => 'node',
      'field' => 'changed',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', _improved_admin_get_content_filters());
  $handler->override_option('access', array(
    'type' => 'perm',
    'perm' => 'administer nodes',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Content');
  $handler->override_option('empty', 'There are no objects satisfying the filter settings. Try changing them to get some results.');
  $handler->override_option('empty_format', '1');
  $handler->override_option('items_per_page', 50);
  $handler->override_option('use_pager', '1');
  $style = (module_exists('views_bulk_operations')) ? 'bulk' : 'table';
  $handler->override_option('style_plugin', $style);
  $handler->override_option('style_options', _improved_admin_get_content_style_opts($style));
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->override_option('filters', _improved_admin_get_content_filters());
  $handler->override_option('path', 'admin/content/node/improved');
  $handler->override_option('menu', array(
    'type' => 'normal',
    'title' => 'Improved Listing',
    'description' => '',
    'weight' => '0',
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));

  $views[$view->name] = $view;
  return $views;
}

function _improved_admin_get_content_fields() {
  $fields['title'] =  array(
      'label' => 'Title',
      'link_to_node' => 1,
      'exclude' => 0,
      'id' => 'title',
      'table' => 'node',
      'field' => 'title',
      'relationship' => 'none',
      'override' => array(
        'button' => 'Override',
      ),
    );
    if (module_exists('og_views')) {
      $fields['group_nid'] = array(
        'label' => 'Groups',
        'alter' => array(
          'alter_text' => FALSE,
          'text' => '',
          'make_link' => FALSE,
          'path' => '',
          'alt' => '',
          'link_class' => '',
          'prefix' => '',
          'suffix' => '',
          'target' => '',
          'trim' => FALSE,
          'max_length' => '',
          'word_boundary' => TRUE,
          'ellipsis' => TRUE,
          'strip_tags' => FALSE,
          'html' => FALSE,
        ),
        'empty' => '',
        'hide_empty' => 0,
        'empty_zero' => 0,
        'type' => 'separator',
        'separator' => ', ',
        'exclude' => 0,
        'id' => 'group_nid',
        'table' => 'og_ancestry',
        'field' => 'group_nid',
        'override' => array(
          'button' => 'Override',
        ),
        'relationship' => 'none',
      );
    }
    $fields['timestamp'] = array(
      'label' => 'New?',
      'link_to_node' => 0,
      'comments' => 0,
      'exclude' => 0,
      'id' => 'timestamp',
      'table' => 'history_user',
      'field' => 'timestamp',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    );
    $fields['type'] = array(
      'label' => 'Type',
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    );
    $fields['name'] = array(
      'label' => 'Author',
      'link_to_user' => 1,
      'exclude' => 0,
      'id' => 'name',
      'table' => 'users',
      'field' => 'name',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    );
    $fields['status'] = array(
      'label' => 'Published',
      'type' => 'yes-no',
      'not' => 0,
      'exclude' => 0,
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    );
    if (module_exists('translation')) {
      $fields['language'] = array(
        'label' => 'Language',
        'alter' => array(
          'alter_text' => 0,
          'text' => '',
          'make_link' => 0,
          'path' => '',
          'link_class' => '',
          'alt' => '',
          'prefix' => '',
          'suffix' => '',
          'target' => '',
          'help' => '',
          'trim' => 0,
          'max_length' => '',
          'word_boundary' => 1,
          'ellipsis' => 1,
          'html' => 0,
          'strip_tags' => 0,
        ),
        'empty' => '',
        'hide_empty' => 0,
        'empty_zero' => 0,
        'link_to_node' => 0,
        'exclude' => 0,
        'id' => 'language',
        'table' => 'node',
        'field' => 'language',
        'override' => array(
          'button' => 'Override',
        ),
        'relationship' => 'none',
      );
    }
    $fields['edit_node'] = array(
      'label' => 'Edit',
      'text' => '',
      'exclude' => 0,
      'id' => 'edit_node',
      'table' => 'node',
      'field' => 'edit_node',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    );
  return $fields;
}

function _improved_admin_get_content_filters() {
  $filters['title'] = array(
    'operator' => 'contains',
    'value' => '',
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'title_op',
      'identifier' => 'title',
      'label' => 'Title contains',
      'optional' => 1,
      'remember' => 0,
    ),
    'case' => 0,
    'id' => 'title',
    'table' => 'node',
    'field' => 'title',
    'override' => array(
      'button' => 'Override',
    ),
    'relationship' => 'none',
  );
  $filters['type'] = array(
    'operator' => 'in',
    'value' => array(),
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'use_operator' => 0,
      'operator' => 'type_op',
      'identifier' => 'type',
      'label' => 'Type',
      'optional' => 1,
      'single' => 0,
      'remember' => 1,
      'reduce' => 0,
    ),
    'id' => 'type',
    'table' => 'node',
    'field' => 'type',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  );
  $filters['status'] = array(
    'operator' => '=',
    'value' => 'All',
    'group' => '0',
    'exposed' => TRUE,
    'expose' => array(
      'operator' => '',
      'identifier' => 'status',
      'label' => 'Published',
      'optional' => 1,
      'remember' => 1,
    ),
    'id' => 'status',
    'table' => 'node',
    'field' => 'status',
    'override' => array(
      'button' => 'Use default',
    ),
    'relationship' => 'none',
  );
  if (module_exists('og_views')) {
    $filters['group_nid'] = array(
      'operator' => 'or',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'group_nid_op',
        'identifier' => 'group_nid',
        'label' => 'Groups',
        'optional' => 1,
        'single' => 0,
        'remember' => 1,
        'reduce' => 0,
      ),
      'id' => 'group_nid',
      'table' => 'og_ancestry',
      'field' => 'group_nid',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
      'reduce_duplicates' => 0,
    );
  }
  if (module_exists('translation')) {
    $filters['language'] = array(
      'operator' => 'in',
      'value' => array(),
      'group' => '0',
      'exposed' => TRUE,
      'expose' => array(
        'use_operator' => 0,
        'operator' => 'language_op',
        'identifier' => 'language',
        'label' => 'Language',
        'optional' => 1,
        'single' => 0,
        'remember' => 1,
        'reduce' => 0,
      ),
      'id' => 'language',
      'table' => 'node',
      'field' => 'language',
      'override' => array(
        'button' => 'Use default',
      ),
      'relationship' => 'none',
    );
  }
  return $filters;
}

function _improved_admin_get_content_style_opts($style = 'table') {
  switch ($style) {
    case 'bulk':
      $opts = array(
        'grouping' => '',
        'override' => 1,
        'sticky' => 0,
        'order' => 'asc',
        'columns' => array(
          'title' => 'title',
          'timestamp' => 'title',
          'type' => 'type',
          'name' => 'name',
          'status' => 'status',
          'edit_node' => 'edit_node',
        ),
        'info' => array(
          'title' => array(
            'sortable' => 1,
            'separator' => '&nbsp;',
          ),
          'timestamp' => array(
            'separator' => '',
          ),
          'type' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'name' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'status' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'edit_node' => array(
            'separator' => '',
          ),
        ),
        'default' => '-1',
        'execution_type' => '1',
        'display_type' => '0',
        'hide_select_all' => 0,
        'skip_confirmation' => 0,
        'display_result' => 1,
        'merge_single_action' => 0,
        'selected_operations' => array(
          'node_assign_owner_action' => 'node_assign_owner_action',
          'views_bulk_operations_delete_node_action' => 'views_bulk_operations_delete_node_action',
          'views_bulk_operations_script_action' => 'views_bulk_operations_script_action',
          'node_make_sticky_action' => 'node_make_sticky_action',
          'node_make_unsticky_action' => 'node_make_unsticky_action',
          'views_bulk_operations_fields_action' => 'views_bulk_operations_fields_action',
          'views_bulk_operations_taxonomy_action' => 'views_bulk_operations_taxonomy_action',
          'node_promote_action' => 'node_promote_action',
          'node_publish_action' => 'node_publish_action',
          'node_unpromote_action' => 'node_unpromote_action',
          'node_unpublish_action' => 'node_unpublish_action',
        ),
      );
      break;
    case 'table':
      $opts = array(
        'grouping' => '',
        'override' => 1,
        'sticky' => 1,
        'order' => 'asc',
        'columns' => array(
          'title' => 'title',
          'timestamp' => 'title',
          'group_nid' => 'group_nid',
          'type' => 'type',
          'name' => 'name',
          'status' => 'status',
          'language' => 'language',
          'edit_node' => 'edit_node',
        ),
        'info' => array(
          'title' => array(
            'sortable' => 1,
            'separator' => '&nbsp;',
          ),
          'group_nid' => array(
            'separator' => '',
          ),
          'timestamp' => array(
            'separator' => '',
          ),
          'type' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'name' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'status' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'language' => array(
            'sortable' => 1,
            'separator' => '',
          ),
          'edit_node' => array(
            'separator' => '',
          ),
        ),
        'default' => '-1',
      );
      break;
  }
  return $opts;
}