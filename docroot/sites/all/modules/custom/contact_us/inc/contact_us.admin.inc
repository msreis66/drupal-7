<?php

/**
 * @file
 * Contains functions related to admin forms.
 */

/**
 * Form function for submissions list.
 *
 * @param array $form
 *   Form structure.
 */
function contact_us_submissions_form(array $form = []) {
  module_load_include('inc', 'contact_us', 'inc/contact_us.common');

  // Creates fieldset for form.
  $form['submissions'] = [
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#title' => 'submissions test',
    '#header' => [
      'SID',
      'First Name',
      'Last Name',
      'Email',
      'Subject',
      'Created',
      'Operations',
    ],
    '#theme' => 'contact_us_submissions',
  ];

  // Gets all submissions and include on form.
  $submissions = contact_us_get_submissions()->fetchAll(PDO::FETCH_ASSOC);
  foreach ($submissions as $submission) {
    $form['submissions']['results'][] = [
      '#tree' => TRUE,
      'sid' => [
        '#markup' => $submission['sid'],
      ],
      'first_name' => [
        '#markup' => $submission['first_name'],
      ],
      'last_name' => [
        '#markup' => $submission['last_name'],
      ],
      'email' => [
        '#markup' => $submission['email'],
      ],
      'subject' => [
        '#markup' => $submission['subject'],
      ],
      'created' => [
        '#markup' => $submission['created'],
      ],
    ];
  }

  return $form;
}

/**
 * Theme function to render submissions.
 *
 * @param array $vars
 *   Variables received from form function.
 */
function theme_contact_us_submissions(array $vars = []) {
  global $base_url;

  $form = $vars['form'];

  // Defines rows to be rendered.
  $rows = [];
  foreach (element_children($form['results']) as $key) {
    $row = [];
    $row['sid'] = drupal_render($form['results'][$key]['sid']);
    $row[] = drupal_render($form['results'][$key]['first_name']);
    $row[] = drupal_render($form['results'][$key]['last_name']);
    $row[] = drupal_render($form['results'][$key]['email']);
    $row[] = drupal_render($form['results'][$key]['subject']);
    $row[] = drupal_render($form['results'][$key]['created']);
    $row[] = "<a href='{$base_url}/admin/contact-us/submission/{$row['sid']}'>" . t('View') . "</a>";
    $rows[] = $row;
  }

  return theme('table', ['header' => $form['#header'], 'rows' => $rows]);
}

/**
 * Form function for answer form.
 *
 * @param array $form
 *   Form structure.
 */
function contact_us_answer_form(array $form = []) {
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
 * Form submit function.
 *
 * @param array $form
 *   Form structure.
 * @param array $form_state
 *   Form state values.
 */
function contact_us_answer_form_submit(array $form = [], array &$form_state = []) {
  $email_to = $form_state['build_info']['args'][0];
  $email_from = variable_get('site_mail', ini_get('sendmail_from'));

  $module = 'contact_us';
  $key = 'answer_submission';
  $system = drupal_mail_system($module, $key);
  $message = [
    'id' => "{$module}_{$key}",
    'from' => $email_from,
    'to' => $email_to,
    'subject' => 'Subject',
    'body' => 'Message',
    'headers' => [
      'From' => $email_from,
      'Sender' => $email_from,
      'Return-Path' => $email_from,
      'Content-Type' => 'text/html; charset=UTF-8',
    ],
  ];
  $system->mail($message);
}

/**
 * Callback function to render submission view content.
 *
 * @param int $sid
 *   Submission id.
 */
function contact_us_submission_view($sid) {
  module_load_include('inc', 'contact_us', 'inc/contact_us.common');
  $condition = ['sid' => $sid];
  $submission = contact_us_get_submissions($condition)->fetchAssoc();
  
  if (empty($submission)) {
    drupal_not_found();
    drupal_exit();
  }

  return theme('contact_us__submission_view', [
    'submission' => $submission,
    'answer_form' => drupal_get_form('contact_us_answer_form', $submission['email']),
  ]);
}
