<?php

/**
 * @file
 * Template to display submission details.
 *
 * Variables:
 * - $submission: The submission values.
 * - $answer_form: Answer form structure.
 */
?>

<div id="page">
  <div id="content" class="clearfix">
    <div class="element-invisible"><a id="main-content"></a></div>
    <div class="submissions-view">
      <h3><?php print t('Submission ID:'); ?></h3><span><?php print $submission['sid']; ?></span>
      <h3><?php print t('First name:'); ?></h3><span><?php print $submission['first_name']; ?></span>
      <h3><?php print t('Last name:'); ?></h3><span><?php print $submission['last_name']; ?></span>
      <h3><?php print t('Email:'); ?></h3><span><?php print $submission['email']; ?></span>
      <h3><?php print t('Subject:'); ?></h3><span><?php print $submission['subject']; ?></span>
      <h3><?php print t('Message:'); ?></h3><span><?php print $submission['message']; ?></span>
      <h3><?php print t('Created:'); ?></h3><span><?php print $submission['created']; ?></span>
    </div>
  </div>

  <div class="answer-form">
    <h2><?php print t('Answer this message'); ?></h2>
    <?php print render($answer_form); ?>
  </div>

</div>
