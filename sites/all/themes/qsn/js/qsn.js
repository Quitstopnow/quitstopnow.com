(function ($) {

  var qsn = {

    init: function(context) {
      if($('.view-homepage-bottom-3').length){
        qsn.setIconsOnBottom3();
      }
    },

    setIconsOnBottom3: function(context) {
      $('.field-name-field-cb-content a').each(function(index){
          if( $(this).data('surcharge') ){
            surchargeTotal = surchargeTotal + $(this).data('surcharge');
          }
        $(this).append(' <i class="fa fa-caret-right"></i>');
      });
    }
  }

  Drupal.behaviors.pleatz_m2m = {
    attach: function(context) {
      $('body', context).once(function () {
        qsn.init();
      });
    }
  };

})(jQuery);
