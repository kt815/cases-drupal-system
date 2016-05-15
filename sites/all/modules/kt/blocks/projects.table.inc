<?php 

function kt_projects_table_block_view() 
{


$query = db_select('node', 'n');
$query->fields('n', array('nid', 'title', 'created'));
$query->fields('fdfd', array('field_description_value'));
$query->fields('ua', array('alias'));
$query->innerJoin('field_data_field_description', 'fdfd', 'n.nid = fdfd.entity_id');
$query->innerJoin('url_alias', 'ua', 'ua.source = CONCAT(:nodeid, n.nid)', array(':nodeid' => 'node/'));
$query->condition('n.type', 'article');
$query->orderBy('created', 'DESC');
$result = $query->execute();

$out = '';

foreach ($result as $row) {
  
  $timestamp = $row->created;
  $month = date("F", $timestamp);
  $year = date("Y", $timestamp);

  $out .= '
      <div class="projects__more col-xs-12">
        <div class="projects__date">
          <div class="projects__month">' . $month . '</div>
          <div class="projects__year">' . $year . '</div>
        </div>
        <div class="projects__about">
          <div class="projects__title">' . $row->title . '</div>
          <div class="projects__subtitle">' . $row->field_description_value . '</div>
        </div>
        <div class="projects__actions"><a href="/' . $row->alias . '" class="projects__btn btn-sm btn-ghost btn-primary"><i class="fa fa-info-circle"></i>More info    </a></div>
      </div>
  ';

}

  $var = '<div class="page__wrapper_left"><div class="projects">' . $out . '</div></div>';

  $output = t($var);
  return $output;   

}

