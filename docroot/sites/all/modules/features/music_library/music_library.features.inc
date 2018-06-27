<?php
/**
 * @file
 * music_library.features.inc
 */

/**
 * Implements hook_views_api().
 */
function music_library_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function music_library_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favourite".
  $flags['favourite'] = array(
    'entity_type' => 'node',
    'title' => 'Favourite',
    'global' => 0,
    'types' => array(
      0 => 'music_track',
    ),
    'flag_short' => 'Favourite this ',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Un-favourite',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'music_library',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function music_library_node_info() {
  $items = array(
    'album' => array(
      'name' => t('Album'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'artist' => array(
      'name' => t('Artist'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'music_track' => array(
      'name' => t('Music track'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'video_series' => array(
      'name' => t('Video series'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'videos' => array(
      'name' => t('Videos'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
