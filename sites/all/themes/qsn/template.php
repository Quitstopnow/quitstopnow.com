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

  // Set up new regions
  $variables['content_below'] = $variables['page']['content_below'];
  $variables['footer_below'] = $variables['page']['footer_below'];

  if(is_numeric(arg(1)) && (arg(1) == 1)){
    drupal_set_title('');
    $variables['home_slider'] = $variables['page']['home_slider'];
  }
}

function qsn_item_list($variables){
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '<div class="item-list">';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      // For the bottom 3 blocks on the homepage
      if (strpos($data,'field-content-blocks') !== false) {
        $attributes['class'][] = 'col-md-4 col-sm-4';
      }

      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  $output .= '</div>';
  return $output;
}

