DESCRIPTION
-----------

Drupal module that is an improved alternative to the default content admin page.
Improved Admin gets better when the modules listed below are enabled.

USAGE
-----------

Enable the module. You will also want to download and enable several other modules that enhance 
Improved Admin

[Views Bulk Operations] - http://drupal.org/project/views_bulk_operations

Views Bulk Operations is pretty much a requirement for this module to be worth anything. 
With VBO, Improved Admin will work very similar to the VBO emulated admin view.


[OG Views] - http://drupal.org/project/og

Organic Groups project contains a module called og_views that provides views integration. 
When og_views in enabled, an exposed filter by group is displayed and a column that lists the groups
that nodes are posted to is displayed.

[Content Translation] - Core

When Locale and Content Translation are enabled, exposed filters for language selection and a 
flag for whether or not translation is needed are shown.

Two new columns are displayed. The language column lists the language the content is posted under
and if content translation is supported, a link to translate the node to another language is
provided.  The translation needed column displays the value of a flag on whether or not
translation is needed.

[Pathauto] - http://drupal.org/project/pathauto

When pathauto is enabled along with VBO, a new action to bulk update URL aliases is provided.

[Node Export] - http://drupal.org/project/node_export

When node export is enabled along with VBO, a new action to bulk export nodes is provided.

CREDITS
-----------

Developed by Dustin Currie <dustin@onlinedesert.com>
