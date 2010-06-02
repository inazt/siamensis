$(document).ready(function() {

  // This is an array to keep track of messages coming it which have already been displayed on the page.
  var alreadyGrowled = new Array();

  /**
   * Check for new private messages and alert the user if there are new messages available
   */
  var pmGrowlCheckNew = function() {

    // Make the request to check for new messages and provide callback for request
    $.getJSON(Drupal.settings.basePath + 'messages/pmgrowl_json', function(data) {
      $(data).each(function(entryIndex, entry) {
        // For reach entry that comes back, check if it's a new message and set newMessage accordingly
        var newMessage = true;
        $(alreadyGrowled).each(function(index, mid) {
          if(entry['mid'] == mid) {
            newMessage = false;
          }
        });

        // Now if it is a new message, display the Growl notification, and add this message to array of messages already displayed
        if(newMessage == true) {
          $.jGrowl(entry['body'],
            {
              sticky: true,
              header: entry['subject'],
              beforeClose : function(e, m) {
                $.post(Drupal.settings.basePath + 'messages/pmgrowl_close', { mid : entry['mid'] });
              }
            }
          );
          alreadyGrowled.push(entry['mid']);
        }
      });
    });
  }

  // make the initial call on page load
  pmGrowlCheckNew();

  // set the timer to check for new messages on a given interval 
  if (Drupal.settings.pmGrowlInterval != 0) {
    var messageTimer = setInterval(pmGrowlCheckNew, Drupal.settings.pmGrowlInterval);
  }
});
