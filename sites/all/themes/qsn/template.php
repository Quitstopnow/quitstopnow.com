<?php

/**
 * @file
 * template.php
 */
// Pleatz Preprocess Node
function qsn_preprocess_node(&$variables) {
  global $user;
  // dpm($variables);
  // if($variables['type'] == 'webform'){
  //   if($variables['webform_block'] === TRUE){
  //     $variables['title'] = false;
  //   }
  // }
}

// QSN Preprocess Page
function qsn_preprocess_page(&$variables) {
  // unset container class of nav bar
  unset($variables['navbar_classes_array'][1]);

  // Set up a new region below the footer..
  $variables['footer_below'] = $variables['page']['footer_below'];
}
