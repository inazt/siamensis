<?php
// $Id: content_timelock.admin.inc,v 1.1.2.4 2010/04/18 12:39:20 eugenmayer Exp $

# Copyright (c) 2010 Impressive.media
# Author: Eugen Mayer
/*
 * Providing a administration interface for tagging.
 */
function content_timelock_admin_settings() {
  $form['content_timelock_live_time'] = array(
    '#type'=>'textfield',
    '#title' => t('Set live time for forum'),
    '#description' => t('If you set this option your forum will automatic lock in ___ hours'),
    '#default_value' => variable_get('content_timelock_live_time',24),
  );
  $form['content_timelock_error_message'] = array(
    '#type'=>'textfield',
    '#title' => t('Set error timelock message for forum'),
    '#description' => t('error message for forumnakub'),
    '#default_value' => variable_get('content_timelock_error_message',t('Error pass 24 hours arleady ^^')),
  );
  $form['content_timelock_admin_verbose'] = array(
      '#type' => 'checkbox',
      '#title' => t('Show lock / unlock messages'),
      '#description' => t('If you disable this option, no messages about unlock / lock of nodes are shown to the user anymore'),
      '#default_value' => variable_get('content_timelock_admin_verbose', true),
  );

  $form['content_timelock_admin_cancelbutton'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add cancel button'),
      '#description' => t('Should a cancel button be added to the node / user / comment form. This way a user can properly cancel the transaction'),
      '#default_value' => variable_get('content_timelock_admin_cancelbutton', true),
  );

  return system_settings_form($form);
}