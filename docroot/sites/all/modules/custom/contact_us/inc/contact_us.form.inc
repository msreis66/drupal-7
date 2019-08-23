<?php

/**
 * @file
 * Contains functions related to contact_us form for end users.
 */

/**
 * Form function for contact us form.
 *
 * @param array $form
 *   Form structure.
 */
function contact_us_form(array $form = []) {
  $form['contact_us_first_name'] = [
    '#type' => 'textfield',
    '#title' => 'First Name',
    '#required' => TRUE,
  ];

  $form['contact_us_last_name'] = [
    '#type' => 'textfield',
    '#title' => 'Last Name',
    '#required' => TRUE,
  ];

  $form['contact_us_email'] = [
    '#type' => 'textfield',
    '#title' => 'Email',
    '#required' => TRUE,
  ];

  $form['contact_us_subject'] = [
    '#type' => 'textfield',
    '#title' => 'Subject',
    '#required' => TRUE,
  ];

  $form['contact_us_message'] = [
    '#type' => 'textarea',
    '#title' => 'Message',
    '#required' => TRUE,
    '#width' => 30,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Submit',
  ];

  return $form;
}

/**
 * Form validate function.
 *
 * @param array $form
 *   Form structure.
 * @param array $form_state
 *   Form state values.
 */
function contact_us_form_validate(array $form = [], array &$form_state = []) {
  // Sets form error if the email entered by user is not valid.
  if (!valid_email_address($form_state['values']['contact_us_email'])) {
    form_set_error('contact_us_email', t('Enter a valid email address!'));
  }
}

/**
 * Form submit function.
 *
 * @param array $form
 *   Form structure.
 * @param array $form_state
 *   Form state values.
 */
function contact_us_form_submit(array $form = [], array &$form_state = []) {
  module_load_include('inc', 'contact_us', 'inc/contact_us.common');
  form_state_values_clean($form_state);
  $values = $form_state['values'];
  contat_us_create_submission($values);
}
