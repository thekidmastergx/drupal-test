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
        <?php print $left; ?>
      </aside>
      <section id="blog-area">
        <?php print $content; ?>
      </section>
    </div>
    <footer id="ending-blurb">
      <hr>
      <?php if (!empty($footer)): print $footer; endif; ?>
      <p class="message">
        <?php print $closure ?>
      </p>
      <br>
      <?php print $feed_icons ?>
      <div class="banner">
        <span style="font-family:georgia,arial,helvetica,sans-serif;font-size:12px;color:#ffffff;font-weight:bold"><?php print $footer_message; ?></span>
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
