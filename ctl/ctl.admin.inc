<?php

/**
 * @file
 *
 * This file provides the admin form for the ctl module.
 */

/**
 * Provides the ctl administration form.
 */
function ctl_admin_settings_form($form_state) {
  $form['tasks'] = array(
    '#type' => 'fieldset',
    '#title' => t('Available links'),
    '#description' => t('Activate the links you want to display in your toolbar'),
  );
  $local_tasks = menu_local_tasks();
  foreach ($local_tasks as $key => $local_task) {
    if ($key == 'root_path')
      continue;
    $form['tasks']['fieldset_' . $key] = array(
      '#type' => 'fieldset',
      '#title' => check_plain(ucfirst($key)),
    );
    $form['tasks']['fieldset_' . $key]['ctl_use_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => t('Display'),
      '#default_value' => variable_get('ctl_use_' . $key, 0),
    );
    $form['tasks']['fieldset_' . $key]['ctl_reverse_' . $key] = array(
      '#type' => 'checkbox',
      '#title' => t('Reverse order'),
      '#default_value' => variable_get('ctl_reverse_' . $key, 0),
    );
    if ($key == 'tabs') {
      $form['tasks']['fieldset_' . $key]['ctl_rewrite_view'] = array(
        '#type' => 'checkbox',
        '#title' => t('Display internal path in separate button.'),
        '#default_value' => variable_get('ctl_rewrite_view', 0),
      );
    }
  }
  return system_settings_form($form);
}
