<?php

/**
 * @file
 * tlconverter Module Run test Form.
 */

/**
 * Form for setting up request settings.
 */
function tlconverter_run_test_form($form, &$form_state) {

  $form = array();

  $form['tlconverter_sheet'] = array(
    '#type' => 'managed_file',
    '#title' => t('HTML'),
    '#description' => t('Upload html'),
    '#upload_location' => 'public://tlconverter',
    '#upload_validators' => array(
      'file_validate_extensions' => array('html'),
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
    '#ajax' => array(
      'callback' => 'tlconverter_ajax_run_test',
      'method' => 'replace',
      'effect' => 'fade',
    ),
  );

  return $form;
}

/**
 * Submit function for testing form.
 */
function tlconverter_ajax_run_test($form, &$form_state) {
  $fid = $form_state['values']['tlconverter_sheet'];

  $file = file_load($fid);

  dpm($file->uri);

  require_once DRUPAL_ROOT . '\sites\all\modules\contrib\simplehtmldom\simplehtmldom\simple_html_dom.php';
  $html = file_get_html($file->uri);


   dpm('teast');
   dpm($html);
   dpm('wat');

   return array(ajax_commands_replace('#ssxu', 'xuza'));
}
