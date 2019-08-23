<?php

/**
 * @file
 * Contains common function used for contact_us module.
 */

/**
 * Gets all submissions or specific ones.
 *
 * @param array $conditions
 *   Condition for select query.
 */
function contact_us_get_submissions(array $conditions = []) {
  $query = db_select('contact_us_submission', 'submissions')
    ->fields('submissions');

  // Adds conditions if existing.
  foreach ($conditions as $condition => $value) {
    $query->condition($condition, $value, '=');
  }

  return $query->execute();
}

/**
 * Creates a new submission.
 *
 * @param array $data
 *   Contains data entered by user in form.
 */
function contat_us_create_submission(array $data = []) {
  db_insert('contact_us_submission')
    ->fields(
      [
        'first_name' => $data['contact_us_first_name'],
        'last_name' => $data['contact_us_last_name'],
        'email' => $data['contact_us_email'],
        'subject' => $data['contact_us_subject'],
        'message' => $data['contact_us_message'],
        'created' => time(),
      ]
    )
    ->execute();
}
