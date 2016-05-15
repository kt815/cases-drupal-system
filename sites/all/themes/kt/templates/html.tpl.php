<!DOCTYPE HTML>
<html>
  <head>
  	<title><?php print $head_title; ?></title>
    <meta charset="utf-8">
    <meta name="description" content="My Cases">
    <meta name="author" content="my.cases">
    <meta http-equiv="Cache-Control" content="no-cache, no-store, must-revalidate">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.5.0/css/font-awesome.min.css">
    <link rel="stylesheet" type="text/css" href="<?php print base_path() . path_to_theme(); ?>/css/app.css">
    <link rel="stylesheet" type="text/css" href="<?php print base_path() . path_to_theme(); ?>/css/cases.css">
    <link href="https://fonts.googleapis.com/css?family=Roboto+Condensed:400,700,300" rel="stylesheet" type="text/css">
    <link href="https://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
  </head>
<body>
 <div class="header__gradient"></div>
 <div class="page__wrapper">   

  <?php print $page; ?>

 </div>

<script type="text/javascript">
    jQuery(document).ready(function($){

        var url = window.location.href.split('/');

        $('nav a').each(function() {  
                if($(this).attr('href') == ('/' + url[3])){
                  $(this).addClass("active");  
                }
        });



    });
</script>  

</body>		
</html>
