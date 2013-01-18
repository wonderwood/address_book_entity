<?php

function address_book_views_default_views(){
  $view = new view();
  $view->name = 'address_book_admin_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'edu_contacts';
  $view->human_name = 'Address book admin page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Test';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer address book';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'cid' => 'cid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Address book contact */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'edu_contacts';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '<!--views-bulk-operations-select-all-->';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 1,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 0,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Address book contact: Address book contact ID */
  $handler->display->display_options['fields']['cid']['id'] = 'cid';
  $handler->display->display_options['fields']['cid']['table'] = 'edu_contacts';
  $handler->display->display_options['fields']['cid']['field'] = 'cid';
  $handler->display->display_options['fields']['cid']['label'] = 'ID';
  /* Field: Address book contact: Photo */
  $handler->display->display_options['fields']['field_contact_photo']['id'] = 'field_contact_photo';
  $handler->display->display_options['fields']['field_contact_photo']['table'] = 'field_data_field_contact_photo';
  $handler->display->display_options['fields']['field_contact_photo']['field'] = 'field_contact_photo';
  $handler->display->display_options['fields']['field_contact_photo']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_contact_photo']['alter']['path'] = 'address_book/[cid]';
  $handler->display->display_options['fields']['field_contact_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_contact_photo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Address book contact: Birthday */
  $handler->display->display_options['fields']['field_contact_birthday']['id'] = 'field_contact_birthday';
  $handler->display->display_options['fields']['field_contact_birthday']['table'] = 'field_data_field_contact_birthday';
  $handler->display->display_options['fields']['field_contact_birthday']['field'] = 'field_contact_birthday';
  /* Field: Address book contact: Category */
  $handler->display->display_options['fields']['field_contact_category']['id'] = 'field_contact_category';
  $handler->display->display_options['fields']['field_contact_category']['table'] = 'field_data_field_contact_category';
  $handler->display->display_options['fields']['field_contact_category']['field'] = 'field_contact_category';
  $handler->display->display_options['fields']['field_contact_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Address book contact: E-mail */
  $handler->display->display_options['fields']['field_contact_e_mail']['id'] = 'field_contact_e_mail';
  $handler->display->display_options['fields']['field_contact_e_mail']['table'] = 'field_data_field_contact_e_mail';
  $handler->display->display_options['fields']['field_contact_e_mail']['field'] = 'field_contact_e_mail';
  /* Field: Address book contact: First name */
  $handler->display->display_options['fields']['field_contact_first_name']['id'] = 'field_contact_first_name';
  $handler->display->display_options['fields']['field_contact_first_name']['table'] = 'field_data_field_contact_first_name';
  $handler->display->display_options['fields']['field_contact_first_name']['field'] = 'field_contact_first_name';
  $handler->display->display_options['fields']['field_contact_first_name']['exclude'] = TRUE;
  /* Field: Address book contact: Last name */
  $handler->display->display_options['fields']['field_contact_last_name']['id'] = 'field_contact_last_name';
  $handler->display->display_options['fields']['field_contact_last_name']['table'] = 'field_data_field_contact_last_name';
  $handler->display->display_options['fields']['field_contact_last_name']['field'] = 'field_contact_last_name';
  $handler->display->display_options['fields']['field_contact_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_contact_last_name']['alter']['text'] = '[field_contact_first_name] [field_contact_last_name]';
  $handler->display->display_options['fields']['field_contact_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_contact_last_name']['alter']['path'] = 'address_book/[cid]';
  /* Field: Address book contact: Phone */
  $handler->display->display_options['fields']['field_contact_phone']['id'] = 'field_contact_phone';
  $handler->display->display_options['fields']['field_contact_phone']['table'] = 'field_data_field_contact_phone';
  $handler->display->display_options['fields']['field_contact_phone']['field'] = 'field_contact_phone';
  /* Filter criterion: Address book contact: Category (field_contact_category) */
  $handler->display->display_options['filters']['field_contact_category_tid']['id'] = 'field_contact_category_tid';
  $handler->display->display_options['filters']['field_contact_category_tid']['table'] = 'field_data_field_contact_category';
  $handler->display->display_options['filters']['field_contact_category_tid']['field'] = 'field_contact_category_tid';
  $handler->display->display_options['filters']['field_contact_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_contact_category_tid']['expose']['operator_id'] = 'field_contact_category_tid_op';
  $handler->display->display_options['filters']['field_contact_category_tid']['expose']['label'] = 'Category';
  $handler->display->display_options['filters']['field_contact_category_tid']['expose']['operator'] = 'field_contact_category_tid_op';
  $handler->display->display_options['filters']['field_contact_category_tid']['expose']['identifier'] = 'field_contact_category_tid';
  $handler->display->display_options['filters']['field_contact_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_contact_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_contact_category_tid']['vocabulary'] = 'contact_categories';
  $handler->display->display_options['filters']['field_contact_category_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/address_book/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Address book';
  $handler->display->display_options['tab_options']['description'] = 'Administer address book module';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  $views['address_book_admin_page'] = $view;

  return $views;
}