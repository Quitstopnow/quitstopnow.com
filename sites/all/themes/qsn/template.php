<?php

/**
 * @file
 * template.php
 */
// Pleatz Preprocess Node
function qsn_preprocess_node(&$variables) {
  global $user;
  if($variables['view_mode'] == 'full'){
    if($variables['nid'] == 10){ // My Story
      $variables['title'] = false;
      $fcw = entity_metadata_wrapper('node', $variables['nid']);
      $content_blocks = '<div class="my-story-container">';
      foreach ($fcw->field_content_blocks->getIterator() as $key => $value) {
        $content_blocks .= '<div class="col-md-6 col-sm-6">';
        $img_display = $value->field_cb_image->value();
        $link_display = $value->field_cb_content->value();
        $img_show = theme('image_style', array('style_name'=>'my_story_imgs', 'path'=>$img_display['uri']));
        $content_blocks .= l($img_show, $link_display['value'], array(
          'html' => true,
          'external' => true,
          'attributes' => array(
            'class' => array('fancybox-media'),
          ),
        ));
        $content_blocks .= '</div>';
      }
      $content_blocks .= '</div>';
      $variables['content_blocks'] = $content_blocks;
    }
  }
}

// QSN Preprocess Page
function qsn_preprocess_page(&$variables) {
  // unset container class of nav bar
  unset($variables['navbar_classes_array'][1]);

  if(drupal_is_front_page()){
    $js = '<script type="text/javascript" src="//s3.amazonaws.com/downloads.mailchimp.com/js/signup-forms/popup/embed.js" data-dojo-config="usePlainJson: true, isDebug: false"></script><script type="text/javascript">require(["mojo/signup-forms/Loader"], function(L) { L.start({"baseUrl":"mc.us8.list-manage.com","uuid":"e3d30760e3d6ad306c856f131","lid":"c2666c7a9a"}) })</script>';
    // drupal_add_js($js, array('type' => 'inline', 'scope' => 'header'));
  }

  // Set up new regions
  $variables['content_below'] = $variables['page']['content_below'];
  $variables['footer_below'] = $variables['page']['footer_below'];

  if(is_numeric(arg(1)) && arg(1) == 1){
    drupal_set_title('');
    $variables['home_slider'] = $variables['page']['home_slider'];
  }

  $variables['social_icons'] = '<ul class="unstyled">
    <li>
      <a class="social-wrapper facebook" href="https://www.facebook.com/quitstopnow?fref=ts" target="_blank">
        <span class="social-icon">
          <i class="fa fa-facebook"></i>
        </span>
        <span class="social-title">Follow via Facebook
        </span>
      </a>
    </li>

    <li>
      <a class="social-wrapper twitter" href="https://twitter.com/Quit_Stop_Now" target="_blank">
        <span class="social-icon">
          <i class="fa fa-twitter"></i>
        </span>
        <span class="social-title">Follow via Twitter
        </span>
      </a>
    </li>

    <li>
      <a class="social-wrapper google" href="https://plus.google.com/u/0/b/118072083418495022549/118072083418495022549/posts/p/pub" target="_blank">
        <span class="social-icon">
          <i class="fa fa-google-plus"></i>
        </span>
        <span class="social-title">Follow via Google Plus
        </span>
      </a>
    </li>

    <li>
      <a class="social-wrapper youtube" href="https://www.youtube.com/channel/UCV1VMkHN_pdUsH8UCOsLyrQ/feed?view_as=public" target="_blank">
        <span class="social-icon">
          <i class="fa fa-youtube"></i>
        </span>
        <span class="social-title">Follow via Youtube
        </span>
      </a>
    </li>

    <li class="hide">
      <a class="social-wrapper cart" href="/cart">
        <span class="social-icon">
          <i class="icon-shopping-cart"></i>
        </span>
        <span class="social-title">Cart (<span id="social-cart-num">0</span>)
        </span>
      </a>
    </li>
  </ul>';

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

