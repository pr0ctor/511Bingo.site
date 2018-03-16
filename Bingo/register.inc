<?php require('db.inc');

if(!empty($_POST['username']) && !empty($_POST['password']) && !empty($_POST['register'])) 
{
	$salt = "blah"; //such safe salt
	
	$username = $_POST['username'];
	$pass = $salt.$_POST['password'];
	
	$checkstmt = $db->prepare("
	select id from users where username = ?
	");
	
	$checkstmt->bind_param('s',$username);
	$checkstmt->execute();
	$checkstmt->store_result();
	
	$rows = $checkstmt->num_rows;

	if($rows > 0)
	{
		$_POST['error'] = "User already exists.";
		
		header('Location: register.html');
		
		die;
	}
	
	$stmt = $db->prepare("
	insert into users(username, password) values(?,SHA1(?))
	");

	
	$stmt->bind_param('ss',$username,$pass);
	$stmt->execute();
	
	$registration = 100;

}


?>