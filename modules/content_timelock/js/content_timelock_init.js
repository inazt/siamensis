
(function($) {
  window.content_timelock_onleave = function  () {
    var nid = Drupal.settings.content_timelock.nid;
    var random = Math.random();
    var aurl = "http:/ds.l"+Drupal.settings.basePath + 'index.php?q=ajax/content_timelock/'+nid+'/canceledit&t='+random;
    $.ajax({
      url:   aurl,
      async: false,
      cache:false
    });
  }

  window.content_timelock_confirm = function () {
    return Drupal.t('Be aware, if you press "OK" now, ALL your changes will be lost!');
  }

  $(document).ready(function() {
    $().onUserExit( {
      execute: content_timelock_onleave,
      executeConfirm: content_timelock_confirm,
      internalURLs: 'canceledit|trash/confirm'
    });
  });
})(jQuery);