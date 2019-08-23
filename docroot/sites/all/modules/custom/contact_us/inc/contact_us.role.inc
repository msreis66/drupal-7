<?php

/**
 * @file
 * Contains functions relate to contact_us role.
 */

define('CONTACT_US_REVIEWER_ROLE', 'Contact Us Reviewer');

/**
 * Creates Contact Us Reviewer role.
 */
function contact_us_create_reviewer_role() {
  $contact_us_reviewer_role = new stdClass();
  $contact_us_reviewer_role->name = CONTACT_US_REVIEWER_ROLE;

  try {
    user_role_save($contact_us_reviewer_role);
  }
  catch (Exception $e) {
    watchdog_exception('contact_us', $e);
  }
}

/**
 * Deletes Contact Us Reviewer role.
 */
function contact_us_delete_reviewer_role() {
  try {
    user_role_delete(CONTACT_US_REVIEWER_ROLE);
  }
  catch (Exception $e) {
    watchdog_exception('contact_us', $e);
  }
}
