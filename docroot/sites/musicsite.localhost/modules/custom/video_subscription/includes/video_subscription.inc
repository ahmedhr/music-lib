<?php

function video_subscription($video_series_id) {
  $user_id = $GLOBALS['user']->uid;
  $subscription_id = get_subscription_id($video_series_id, $user_id);
  if (empty($subscription_id)) {
    set_subscription_for_user($video_series_id, $user_id);
    $message = 'Successfuly subscribed to the video series.';
  }
  else {
    $message = 'You are already subscribed to this series';
  }
  drupal_set_message($message);
  drupal_goto();
}

function set_subscription_for_user($video_series_id, $user_id) {
  $query = db_insert('video_subscription');
  $fields = array(
    'video_series_entity_id' => $video_series_id,
    'uid' => $user_id,
    'subscription_time' => time(),
  );
  $query->fields($fields);
  $insert_id = $query->execute();
}
