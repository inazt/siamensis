<?php
// $Id$
/**
  * @file
  * Administration page callbacks for the annotate module.
  */
/**
  * Form builder. Configure annotations.
  *
  * @ingroup forms
  * @see system_settings_form().
  */
function annotate_admin_settings() {
    // Get an array of node types with internal names as keys and
    // "friendly names" as values. E.g.,
    // array('page' => 'Page', 'story' => 'Story')
    $options = node_get_types('names');
    $form['annotate_node_types'] = array(
       '#type' => 'checkboxes',
       '#title' => t('Users may annotate these content types'),
       '#options' => $options,
       '#default_value' => variable_get('annotate_node_types', array('page')),
       '#description' => t('A text field will be available on these content types to
          make user-specific notes.'),
    );
    return system_settings_form($form);
}

