
Can you see that online http://kt815.esy.es

Installation
---------------------

 * git clone https://github.com/kt815/cases-drupal-system.git .

 * Unpack db/db_cases.sql in your database

 * Change sites/default/settings.php (choose your own):
      'database' => 'kt815_d7',
      'username' => 'root',
      'password' => '1',

 * Login: http://localhost/user/
	username: admin
	password: 1


Helpers
---------------------

echo('<pre>');
print_r($row);
echo('<pre>');

SELECT n.nid, n.title
FROM node n
INNER JOIN field_data_body b
ON n.nid = b.entity_id
WHERE n.type = 'article';

SELECT n.nid, n.title, n.created, fdb.body_value, ua.alias
FROM node n
INNER JOIN field_data_body fdb
ON n.nid = fdb.entity_id
INNER JOIN url_alias	ua
ON ua.source = CONCAT('node/', n.nid)
WHERE n.type = 'article';

SELECT n.nid, n.title, n.created, fdb.body_value, ua.alias, fdfi.field_image_alt, fm.filename
FROM node n
INNER JOIN field_data_body fdb
ON n.nid = fdb.entity_id
INNER JOIN url_alias	ua
ON ua.source = CONCAT('node/', n.nid)
INNER JOIN field_data_field_image fdfi
ON fdfi.entity_id = n.nid
INNER JOIN file_managed fm
ON fdfi.field_image_fid = fm.fid
WHERE n.type = 'article'
ORDER BY RAND();