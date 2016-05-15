<?php 

function kt_preprocess_page(&$vars, $hook) {
    unset($vars['page']['content']['system_main']['default_message']);
}

function kt_admin_paths_alter(&$paths) {
    // Treat all user pages as not administrative.
    $paths['user'] = TRUE;
}


?>