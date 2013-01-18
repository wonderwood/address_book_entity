<?php

/**
 * Implements contact add/edit form
 */
function address_book_contactform($form, &$form_state, $contact = NULL) {
  drupal_set_title(t('Add contact'));
  $breadcrumbs   = drupal_get_breadcrumb();
  $breadcrumbs[] = drupal_get_title();
  drupal_set_breadcrumb($breadcrumbs);

  $form['form_intro_text'] = array(
    '#markup' => t('Contact add form intro text, what explains something to user.'),
    '#weight' => 0,
  );

  $form['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Add contact'),
    '#weight' => 90,
  );


  /**
   * check for $contact is not null
   */
  if (!is_null($contact)) {
    /**
     * Query to the DB and check if contact in DB
     * Set default values for form
     * Add hidden field with $cid
     * Add delete link
     * Rewrite submit button text
     */

    // Add custom fields with their values into form
    field_attach_form('contact', $contact, $form, $form_state);

    $form['cid'] = array(
      '#type'   => 'hidden',
      '#value'  => $contact->cid,
      '#weight' => 150,
    );

    $form['delete'] = array(
      '#markup' => l(t('Delete contact'), "admin/address_book/$contact->cid/delete"),
      '#weight' => 100,
    );

    $form['submit']['#value'] = t('Edit contact');

    if (isset($contact->cid)) {
      drupal_set_title(t("Edit contact #@contact_id", array('@contact_id' => $contact->cid)));
      $breadcrumbs   = array();
      $breadcrumbs[] = l(t('Home'), url());
      $breadcrumbs[] = l(t('Address book'), 'address_book');
      $breadcrumbs[] = l($form['#entity']->field_contact_first_name['und']['0']['safe_value'] . ' ' . $form['#entity']->field_contact_last_name['und']['0']['safe_value'], "address_book/$contact->cid");
      $breadcrumbs[] = t('Edit');

      drupal_set_breadcrumb($breadcrumbs);
    }

  }
  else {
    field_attach_form('contact', '', $form, $form_state);
  }

  return $form;
}

function address_book_contactform_validate(&$form, &$form_state) {
}

/**
 *  Implements contact add form submit
 */
function address_book_contactform_submit($form, &$form_state) {
  $entity = new stdClass();
  if (isset($form_state['values']['cid'])) {
    $entity->cid = $form_state['values']['cid'];
  }
  $entity->bundle = 'contact';
  entity_form_submit_build_entity('contact', $entity, $form, $form_state);
  contact_save($entity);

  /**
   * if $cid isset - update entity
   * if $cid not set - save new entity
   */
  if (isset($form_values['values']['cid'])) {
    drupal_set_message(
      t('Contact %cid updated.'),
      array(
        '%cid' => $form_values['values']['cid'],
      ));
    drupal_goto('admin/structure/address_book');
    drupal_set_message(t('Contact edited'));
  }
  else {
    drupal_set_message(t('Contact #%cid successfully added',
      array(
        '%cid' => $entity->cid,
      )));
    drupal_goto('admin/structure/address_book');
  }

}