<?php

function address_book_contact_page_view($contact) {
//  dpm($contact);
  $first_name = $contact->field_contact_first_name['und']['0']['safe_value'];
  $last_name = $contact->field_contact_last_name['und']['0']['safe_value'];

  $title = "$first_name $last_name";
  drupal_set_title($title);

  $breadcrumbs   = drupal_get_breadcrumb();
  $breadcrumbs[] = drupal_get_title();
  drupal_set_breadcrumb($breadcrumbs);
  return entity_view('contact', array(entity_id('contact', $contact) => $contact));
}