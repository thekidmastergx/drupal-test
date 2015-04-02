$Id: README.txt,v 1.3 2011/02/13 19:21:20 serbanghita Exp $

SOCIAL PARSERS FOR FEEDS
============

Agregate public feeds from popular Social Networking and Affiliate Networks sites directly into custom created nodes and views.

Features
========

Able to import from feeds into nodes the following:
- Twitter Search Feeds (eg. http://search.twitter.com/search.atom?q=drupal)
- Facebook Links Feeds (eg. http://www.facebook.com/feeds/share_posts.php?id=1133615313&viewer=1282112668&key=9363a00ee5&format=rss20)
- Avangate.com Affiliate Products Feeds (eg. http://feeds.avangate.com/2880/21481_IZXOFK.xml.gz)


Dependencies
============

Feeds                   http://drupal.org/project/feeds
CCK (Text, Number)      http://drupal.org/project/cck
Views                   http://drupal.org/project/views


Installation
============
1. Unzip the module in sites/all/modules/. Resulting folder should be feeds_social/
2. Go to /admin/build/modules and activate the module.
3. Go to Admin -> Feeds Social Settings under /admin/settings/feeds_social and select
the type of services you want to work with and 'Save settings'
4. Next you should see the 'Import' link (the link should be in your left sidebar).