<?php

function display_video_serie($video_series_id) {
  $user_id = $GLOBALS['user']->uid;
  $subscription_id = get_subscription_id($video_series_id, $user_id);
  if (!empty($subscription_id)) {
    $video_series_node = node_load($subscription_id->video_series_entity_id);
    $subscribed_videos = $video_series_node->field_videos['und'];
    $subscription_time = $subscription_id->subscription_time;
    $subscription_date = new DateTime();
    $subscription_date->setTimestamp($subscription_time);
    $today_date = new DateTime();
    $diff = $today_date->diff($subscription_date)->format("%a");
    $weeks_elapsed = floor($diff / 7);
    $allowed_videos = '';
    for ($i = 0; $i <= $weeks_elapsed; $i++) {
      $video_node = node_load($subscribed_videos[$i]['target_id']);
      $video_node_view = node_view($video_node);
      $allowed_videos .= drupal_render($video_node_view);
    }
    return $allowed_videos;
  }
  else {
    $message = 'You are not subscribed to this series';
    drupal_set_message($message);
    drupal_goto();
  }
}
