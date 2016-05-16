<?php 

function kt_projects_images_block_view() 
{


$query = db_select('node', 'n');
$query->fields('n', array('nid', 'title', 'created'));
$query->fields('fdb', array('body_value'));
$query->fields('ua', array('alias'));
$query->fields('fdfi', array('field_image_alt'));
$query->fields('fm', array('filename'));
$query->innerJoin('field_data_body', 'fdb', 'n.nid = fdb.entity_id');
$query->innerJoin('url_alias', 'ua', 'ua.source = CONCAT(:nodeid, n.nid)', array(':nodeid' => 'node/'));
$query->innerJoin('field_data_field_image', 'fdfi', 'fdfi.entity_id = n.nid');
$query->innerJoin('file_managed', 'fm', 'fdfi.field_image_fid = fm.fid');
$query->condition('n.type', 'article');
$query->orderBy('created', 'DESC');
$result = $query->execute();

  $out = '';

  $i=0;
  foreach ($result as $row) {

  if($i==6) break;
  $out .= '<a href="/' . $row->alias . '" class="project__a col-xs-12 col-sm-4">
      <div class="row">
        <div class="project__img-gutter">
          <div class="zoom"><i class="fa fa-folder-open"></i></div><img src="/sites/default/files/field/image/' . $row->filename . '" alt="Piatto Psd" class="project__img">
        </div>
        <div class="project__title">' . $row->title . '</div>
      </div>
      </a>';
  $i++;

    }

  $var = '<div class="row">' . $out . '</div>';  

  $output = t($var);
  return $output;   

}

