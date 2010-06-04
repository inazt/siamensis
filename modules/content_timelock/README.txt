/* $Id: README.txt,v 1.1.2.11 2010/04/18 12:39:20 eugenmayer Exp $ */
-- Fork --

This module is a fork of the module http://drupal.org/project/checkout and has 
been nearly completely reweritten since then

-- SUMMARY --
This module implements a pessimistic locking strategy, which means that content
will be exclusively locked whenever a user starts editing it.  The lock will be
automatically released when the user submits the form or navigates away from
the edit page.

Users may also permanently lock content, to prevent others from editing it.  
Content locks that have been "forgotten" can be automatically released after a
configurable time span.

For a full description visit the project page:
  http://drupal.org/project/content_lock
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/content_lock


-- REQUIREMENTS --

Working cron, if you wish to make use of automated check-ins.  If your hoster
doesn't allow you to access cron take a look at Poormanscron
(http://drupal.org/project/poormanscron).


-- INSTALLATION --

1. Install as usual, see http://drupal.org/node/70151 for further information.

2. Configure user permissions at User management >> Permissions:

   check out documents - This enables content locking when a user starts
     editing it.  Note that even without this permission, users are still
     able to edit contents, they're just not protected against concurrent
     edits.

   keep documents checked out - Whether to allow users to keep content locked
     across edits.  This will enable a similar named checkbox on the content
     edit form.

   administer checked out documents - View and release locked contents of all
     users.  This enables the administrative tab on Content management >>
     Content.  Note that even without this permission, users can manage their
     own content locks on their profile page.

3. Configure the module at Content management >> Post settings.
   Currently, the only configurable setting is the automatic check-in time span.


-- CREDITS --
Current authors:
Eugen Mayer http://drupal.org/user/108406


Original authors:
Stefan M. Kudwien
Joël Guesclin