<!DOCTYPE html>
<!--[if lt IE 7]> <html class="ie6 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 7]>    <html class="ie7 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if IE 8]>    <html class="ie8 ie" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"> <![endif]-->
<!--[if gt IE 8]> <!-->
<html class="" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<!--<![endif]-->

<head>
  <?php print $head; ?>
  <!-- Set the viewport width to device width for mobile -->
  <meta name="viewport" content="width=device-width" />
  <title>
    <?php print $head_title; ?>
  </title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
  <!-- IE Fix for HTML5 Tags -->
  <!--[if lt IE 9]>
    <script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <style>
    .content-font,
    ,
    p {
      font-family: georgia, arial, helvetica, sans-serif;
      font-size: 12px;
      color: #000000;
    }

    .link-font,
    a {
      font-family: georgia, arial, helvetica, sans-serif;
      font-size: 12px;
      color: #285aaf;
      text-decoration: none;
    }

    .title-font,
    .blog-post-title span,
    .sidebar-widget-title span {
      font-family: georgia, arial, helvetica, sans-serif;
      font-size: 18px;
      color: #285aaf;
      font-weight: bold
    }

    .subtitle-font,
    .blog-post-date {
      font-family: georgia, arial, helvetica, sans-serif;
      font-size: 12px;
      color: #999999
    }

    .sidebar-widget {
      padding: 10px;
    }

    .sidebar-widget-title {
      background-color: #F5F5F5;
      padding: 5px;
    }

    .blog-post {
      display: inline-block;
      margin-bottom: 12px;
      padding: 10px;
    }

    .blog-post-title {
      margin-bottom: 8px;
    }

    .blog-post-image {
      float: right;
      margin-left: 10px;
    }

    body,
    p {
      margin: 0;
    }

    hr {
      min-height: 1px;
      color: #999999;
      border-style: solid;
      border-color: #999999;
      border-width: 1px 0px 0px 0px;
      margin: 5px 15px;
      padding: 5px 10px;
    }

    div#main-card {
      width: 750px;
      border: 1px solid #333333;
      vertical-align: top;
      margin: 0 auto;
    }

    header#banner-card {
      padding: 10px;
      background-color: #333333;
    }

    div#main-container {
      display: inline-flex;
    }

    aside#sidebar-area {
      padding: 10px;
      flex: 0 0 300px;
    }

    section#blog-area {
      padding: 10px;
      flex: 1 100%;
    }

    footer#ending-blurb {}

    footer#ending-blurb .message {
      text-align: center;
    }

    footer#ending-blurb .banner {
      padding: 5px;
      background-color: #333333;
    }
  </style>
</head>

<body class="<?php print $body_classes; ?>">
  <div id="main-card">
    <header id="banner-card" class="banner">
      <table width="100%" cellpadding="5" cellspacing="0" border="0">
        <tbody>
          <tr>
            <?php if ($logo): ?>
            <td width="25%" rowspan="2" valign="top">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
              </a>
            </td>
            <?php endif; ?>
            <?php if ($site_name): ?>
              <td>
                <span style="font-family:georgia,arial,helvetica,sans-serif;font-size:28px;color:#ffffff;font-weight:bold"><?php print $site_name; ?></span>
              </td>
            <?php endif; ?>
            <td align="right">
              <span style="font-family:georgia,arial,helvetica,sans-serif;font-size:28px;color:#6699ff;font-weight:bold">15-108</span>
            </td>
          </tr>
          <?php if ($site_slogan): ?>
            <tr>
              <td colspan="2">
                <hr>
                <span style="font-family:georgia,arial,helvetica,sans-serif;font-size:13px;color:#ffffff;font-weight:bold"><?php print $site_slogan; ?></span>
              </td>
            </tr>
          <?php endif; ?>
        </tbody>
      </table>
    </header>
    <div id="main-container">
      <aside id="sidebar-area">
        <div class="sidebar-widget">
          <div class="sidebar-widget-title ">
            <span>In this Newsletter:</span>
          </div>
          <p class="sidebar-widget-content">
            <br><a href="#14be68ae9eedf1f9_1">Star Wars Marathon</a>
            <br>
            <br>
            <a href="#14be68ae9eedf1f9_2">The Amazing Spider-Man</a>
            <br>
            <br>
            <a href="#14be68ae9eedf1f9_1F">We want YOU. . .</a>
            <br>
            <br>
            <a href="#14be68ae9eedf1f9_2F">March Events</a>
            <br>
            <br>
            <a href="#14be68ae9eedf1f9_CONTACT">Contact Details</a>
            <br>
            <br>
            <a href="#14be68ae9eedf1f9_UNSUB">Subscription Details</a>
          </p>
        </div>
        <div class="sidebar-widget">
          <div class="sidebar-widget-title ">
            <span>We want YOU. . .</span>
          </div>
          <p class="sidebar-widget-content">
            <br>. . To give us your suggestions! Whether you have an idea for a movie you want us to watch, a club event you'd like to see us put on, or a Sci-Friday outing, we'd like to hear ways you think we can make the club even more amazing!
            <br>
            <br>Email them to me personally at the email listed below or to <a href="mailto:tamu.scifi@gmail.com" target="_blank">tamu.scifi@gmail.com</a>!
          </p>
        </div>
        <div class="sidebar-widget">
          <div class="sidebar-widget-title ">
            <span>March Events</span>
          </div>
          <p class="sidebar-widget-content">
            <br>3.7 Star Wars Marathon 1 pm- whenever Annex 417D
            <br>3.8 General Meeting: The Amazing Spiderman
            <br>3.13 No Official Sci-Friday (Spring Break)
            <br>3.14 PI DAY! Make someone a pi pie!
            <br>3.15 No Official Meeting (Spring Break)
            <br>3.20 No Official Meeting (Spring Break)
            <br>3.28 The Big Event</p>
        </div>
        <div class="sidebar-widget">
          <div class="sidebar-widget-title ">
            <span>Contact Details</span>
          </div>
          <p class="sidebar-widget-content">
            <br> Kari Rives
            <br>Vice President, SFA
            <br>
            <br> 9795782669
            <br>
            <a href="mailto:karirives@tamu.edu" target="_blank">karirives@tamu.edu</a>
            <br>
            <a href="http://tamusfa.tamu.edu" target="_blank">tamusfa.tamu.edu</a>
          </p>
        </div>
      </aside>
      <section id="blog-area">
        <article class="blog-post">
          <div class="blog-post-title">
            <span>Star Wars Marathon</span>
          </div>
          <p class="blog-post-date">Episodes IV-VI</p>
          <img class="blog-post-image" src="https://lh3.googleusercontent.com/-KRCpPh1ZJYQ/AAAAAAAAAAI/AAAAAAAAIKw/z_ky4Burdac/photo.jpg">
          <p class="blog-post-content">This weekend, we're doing something classic to us nerds, but new to the club: Star Wars marathon! When the officers learned that certain members (even an officer *gasp*) hadn't seen Star Wars, we knew it needed to be remedied right away, and
            thus, the first marathon was born!
            <br>
            <br>Whether you're interested in experiencing Star Wars for the first time or just watching an old favorite again, head on out to the Annex on Saturday at 1pm to watch with us! We're planning to watch episodes IV-VI, and we know that's a long
            time, so feel free to stop by for a couple of the movies and leave as necessary. It's an unofficial event for the club, and we'd love to see you there!
          </p>
        </article>
        <br>
        <article class="blog-post">
          <div class="blog-post-title">
            <span>The Amazing Spider-Man</span>
          </div>
          <p class="blog-post-date">3.8.15</p>
          <img class="blog-post-image" src="https://ci3.googleusercontent.com/proxy/ixszq978YPTqsu-S6adrKlIk1Ovwa4MYicvvBkMeRLU3-0QPIIcbDYJqkNN709ZEqqQcQBJ_8dc3ewsmhmdYNqYtZb65zoXT8VQxdAmLiIFlqH5ms4w8Jx1aogxS-I_Bo5PqCdr2xDL9=s0-d-e1-ft#http://upload.wikimedia.org/wikipedia/en/f/f8/The_Amazing_Spider-Man_soundtrack.jpg">
          <p class="blog-post-content">The Amazing Spider-Man was originally a Marvel comic book starring Peter Parker, a photographer in high school with a tragic backstory, as the title character. Through a string of events, he obtains superpowers and must fight off villains who
            threaten his family, friends, and secret identity.
            <br>
            <br>... But you already knew that, didn't you? We're watching this movie in an effort to slowly build up everyone's excitement for Age of Ultron ( May 2). Plus, Andrew Garfield and Emma Stone's portrayal of their characters makes this film worth
            watching time and time again, and the moviescore is a pretty excellent mix (check it on Spotify)!
          </p>
        </article>
        <br>
      </section>
    </div>
    <footer id="ending-blurb">
      <hr>
      <p class="message">
        <a name="14be68ae9eedf1f9_UNSUB"></a>You are subscribed to SFA Weekly Announcements. To unsubscribe, visit:
        <br><a href="https://LISTSERV.TAMU.EDU/cgi-bin/wa?SUBED1=SFA&amp;A=1" target="_blank">https://LISTSERV.TAMU.EDU/cgi-<wbr>bin/wa?SUBED1=SFA&amp;A=1</a></p>
      <br>
      <div class="banner">
        <span style="font-family:georgia,arial,helvetica,sans-serif;font-size:12px;color:#ffffff;font-weight:bold">May the Force be ever in your favor!</span>
      </div>
    </footer>
  </div>

  <div id="container" class="clearfix">

    <div id="skip-link">
      <a href="#main-content" class="element-invisible element-focusable">
        <?php print t( 'Skip to main content'); ?>
      </a>
      <?php if ($primary_links): ?>
      <a href="#navigation" class="element-invisible element-focusable">
        <?php print t( 'Skip to navigation'); ?>
      </a>
      <?php endif; ?>
    </div>

    <header id="header" role="banner" class="clearfix">
      <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" id="logo">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>
      <?php if ($site_name || $site_slogan): ?>
      <hgroup id="site-name-slogan">
        <?php if ($site_name): ?>
        <h1 id="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <span>
              <?php print $site_name; ?>
            </span>
          </a>
        </h1>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
        <h2 id="site-slogan">
          <?php print $site_slogan; ?>
        </h2>
        <?php endif; ?>
      </hgroup>
      <?php endif; ?>

      <?php print $header; ?>

      <?php if ($search_box): ?>
      <?php print $search_box ?>
      <?php endif; ?>

      <?php if ($primary_links || $secondary_links || !empty($navigation)): ?>
      <nav id="navigation" role="navigation" class="clearfix ">
        <?php if (!empty($navigation)): ?>
        <!--if block in $navigation region, override $primary_links and $secondary_links-->
        <?php print $navigation ?>
        <?php endif; ?>
        <?php if (empty($navigation)): ?>
        <?php if (isset($primary_links)) : ?>
        <?php print theme(array( 'links__system_main_menu', 'links'), $primary_links, array( 'id'=> 'main-menu', 'class' => 'links clearfix', ), array( 'text' => t('Main menu'), 'level' => 'h2', 'class' => 'element-invisible', )); ?>
        <?php endif; ?>
        <?php if (isset($secondary_links)) : ?>
        <?php print theme(array( 'links__system_secondary_menu', 'links'), $secondary_links, array( 'id'=> 'secondary-menu', 'class' => 'links clearfix', ), array( 'text' => t('Secondary menu'), 'level' => 'h2', 'class' => 'element-invisible', )); ?>
        <?php endif; ?>
        <?php endif; ?>
      </nav>
      <!-- /#navigation -->
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif; ?>
    </header>
    <!-- /#header -->

    <section id="main" role="main" class="clearfix">
      <?php if (!empty($messages)): print $messages; endif; ?>
      <?php if (!empty($mission)): ?>
      <div id="mission">
        <?php print $mission; ?>
      </div>
      <?php endif; ?>
      <a id="main-content"></a>
      <?php if (!empty($title)): ?>
      <h1 class="title" id="page-title">
        <?php print $title ?>
      </h1>
      <?php endif; ?>
      <?php if (!empty($tabs)): ?>
      <div class="tabs-wrapper clearfix">
        <?php print $tabs; ?>
      </div>
      <?php endif; ?>
      <?php if (!empty($help)): print $help; endif; ?>
      <?php print $content; ?>
    </section>
    <!-- /#main -->

    <?php if (!empty($left)): ?>
    <aside id="sidebar-left" role="complementary" class="sidebar clearfix">
      <?php print $left; ?>
    </aside>
    <!-- /sidebar-left -->
    <?php endif; ?>

    <?php if (!empty($right)): ?>
    <aside id="sidebar-right" role="complementary" class="sidebar clearfix">
      <?php print $right; ?>
    </aside>
    <!-- /sidebar-right -->
    <?php endif; ?>

    <footer id="footer" role="contentinfo" class="clearfix">
      <?php print $footer_message; ?>
      <?php if (!empty($footer)): print $footer; endif; ?>
      <?php print $feed_icons ?>
    </footer>
    <!-- /#footer -->

    <?php print $closure ?>

  </div>
  <!-- /#container -->

</body>

</html>
