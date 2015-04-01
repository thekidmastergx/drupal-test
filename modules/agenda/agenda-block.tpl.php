<?php

/**
 * @file
 * Template for displaying the agenda in a block
 */

// Build some neat labels
$labels[$_SERVER['REQUEST_TIME']]         = t('Today');
$labels[$_SERVER['REQUEST_TIME'] - 86400] = t('Yesterday');
$labels[$_SERVER['REQUEST_TIME'] + 86400] = t('Tomorrow');
$keyed_labels = array();
foreach ($labels as $timestamp => $label) {
  $keyed_labels[format_date($timestamp, 'custom', 'Y-m-d')] = $label;
}

// List of keys to display
$keys    = array_map('trim', explode(',', $block->display_keys));
$nolabel = array_map('trim', explode(',', $block->hide_labels)); 
?>
<div class="agenda-block">
  <?php foreach ($events as $day): ?>
  <?php
  $date = format_date($day[0]['start timestamp'], $block->dateformat, $block->customdate);

  // Substitute today/yesterday/tomorrow
  if (isset($keyed_labels[$day[0]['when']])) {
    $date = $keyed_labels[$day[0]['when']];
  }
  ?>
  <p><?php echo $date; ?></p>
  <ol>
  <?php foreach ($day as $event): ?>
    <li class="cal_<?php echo $event['index']; ?>">
      <span class="calendar_title"><?php echo $event['title']; ?></span>
      <ul class="moreinfo">

        <?php foreach ($keys as $key): ?>
          <?php if (!empty($event[$key])): ?>
            <li>
            <?php if (!in_array($key, $nolabel)): ?>
              <em><?php echo _agenda_translate($key); ?></em>: 
            <?php endif; ?>
            <?php echo $event[$key]; ?>
            </li>
          <?php endif; ?>
        <?php endforeach; ?>

      </ul>
    </li>
  <?php endforeach; ?>
  </ol>
<?php endforeach; ?>
</div>