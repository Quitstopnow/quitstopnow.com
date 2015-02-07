<?php
/**
 * @file
 * commerce_sp_paypal.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function commerce_sp_paypal_field_default_fields() {
  $fields = array();

  // Exported field: 'commerce_order-commerce_order-field_commerce_sp_paypal'.
  $fields['commerce_order-commerce_order-field_commerce_sp_paypal'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Off',
          1 => 'On',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_order',
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'Internal setting',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '7',
        ),
        'pdf' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_order',
      'field_name' => 'field_commerce_sp_paypal',
      'label' => 'PayPal recurring billing',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'commerce_product-commerce_sp_subscription-field_commerce_sp_paypal'.
  $fields['commerce_product-commerce_sp_subscription-field_commerce_sp_paypal'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          0 => 'Off',
          1 => 'On',
        ),
        'allowed_values_function' => '',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'list_boolean',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_sp_subscription',
      'commerce_cart_settings' => array(
        'attribute_field' => 0,
        'attribute_widget' => 'select',
      ),
      'default_value' => array(
        0 => array(
          'value' => 0,
        ),
      ),
      'deleted' => '0',
      'description' => 'If set PayPal will handle the recurring billing. The subscription runs as long as it gets cancelled via PayPal.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '4',
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'field_name' => 'field_commerce_sp_paypal',
      'label' => 'PayPal recurring billing',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(
          'display_label' => 1,
        ),
        'type' => 'options_onoff',
        'weight' => '6',
      ),
    ),
  );

  // Exported field: 'commerce_product-commerce_sp_subscription-field_commerce_sp_paypal_periods'.
  $fields['commerce_product-commerce_sp_subscription-field_commerce_sp_paypal_periods'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal_periods',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'global_block_settings' => '1',
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_sp_subscription',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => 'Number of billing periods for the subscription. Enter 2 or more. Leave blank for indefinite subscription that will only expire once cancelled.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => '5',
        ),
        'line_item' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'node_teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'commerce_product',
      'field_name' => 'field_commerce_sp_paypal_periods',
      'label' => 'PayPal billing periods',
      'required' => 0,
      'settings' => array(
        'max' => '',
        'min' => '2',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => '6.5',
      ),
    ),
  );

  // Exported field: 'message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_ipn'.
  $fields['message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_ipn'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal_ipn',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text_long',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_sp_paypal_ipn_log',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_commerce_sp_paypal_ipn',
      'label' => 'IPN full info',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => '5',
        ),
        'type' => 'text_textarea',
        'weight' => '3',
      ),
    ),
  );

  // Exported field: 'message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_ipn_t'.
  $fields['message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_ipn_t'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal_ipn_t',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
        'profile2_private' => FALSE,
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_sp_paypal_ipn_log',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_commerce_sp_paypal_ipn_t',
      'label' => 'IPN type',
      'required' => 0,
      'settings' => array(
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_order'.
  $fields['message-commerce_sp_paypal_ipn_log-field_commerce_sp_paypal_order'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_commerce_sp_paypal_order',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => '0',
      'module' => 'entityreference',
      'settings' => array(
        'handler' => 'base',
        'handler_settings' => array(
          'sort' => array(
            'direction' => 'ASC',
            'field' => 'commerce_line_items:line_item_id',
            'property' => 'order_id',
            'type' => 'none',
          ),
          'target_bundles' => array(
            'commerce_order' => 'commerce_order',
          ),
        ),
        'handler_submit' => 'Change handler',
        'profile2_private' => FALSE,
        'target_type' => 'commerce_order',
      ),
      'translatable' => '0',
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'commerce_sp_paypal_ipn_log',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'message',
      'field_name' => 'field_commerce_sp_paypal_order',
      'label' => 'Order',
      'required' => 0,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'entityreference',
        'settings' => array(
          'match_operator' => 'CONTAINS',
          'path' => '',
          'size' => '60',
        ),
        'type' => 'entityreference_autocomplete',
        'weight' => '1',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('IPN full info');
  t('IPN type');
  t('If set PayPal will handle the recurring billing. The subscription runs as long as it gets cancelled via PayPal.');
  t('Internal setting');
  t('Number of billing periods for the subscription. Enter 2 or more. Leave blank for indefinite subscription that will only expire once cancelled.');
  t('Order');
  t('PayPal billing periods');
  t('PayPal recurring billing');

  return $fields;
}
