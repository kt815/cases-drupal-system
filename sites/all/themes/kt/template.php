<?php 

function kt_preprocess_page(&$vars, $hook) {
    unset($vars['page']['content']['system_main']['default_message']);
}


?>