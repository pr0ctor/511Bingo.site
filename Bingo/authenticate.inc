<?php require('db.inc');
session_start(); // Doesn't hurt to call it twice (or more)
// I use $_REQUEST which checks both $_GET and $_POST
if(!empty($_POST['logout'])) 
{	
	/*unset($_SESSION['user']);
	session_unset();
	
	session_destroy();*/
	header('Location: logout.html');
}
// I'm only using $_POST for logging in – make sure you got your form names correct!
if(!empty($_POST['username']) && !empty($_POST['password'])) 
{
	$salt = "blah"; //such safe salt
	
	$stmt = $db->prepare("
	select id,username,role 
	from users 
	where username = ? and password = SHA1(?)
	");
	
	$pass = $salt.$_POST['password'];
	$stmt->bind_param('ss',$_POST['username'],$pass);
	$stmt->execute();
	$stmt->bind_result($result_id,$result_username,$result_role);
	if($stmt->fetch()) 
	{
		$array = array('userid'=>$result_id,'username'=>$result_username,'role'=>$result_role);
		$_SESSION['user']=$array;
	}
	
	
	/*$salt = "tromalsnad";
	$stmt = $db->prepare("
	select U_ID as id,fname,lname,accesslevel as access from Users
	where email='?'
	and password=password(?)
	");
	$pass = $salt.$_POST['password'];
	$stmt->bind_param('ss',$_POST['email'],$pass);

	if($stmt->execute())
	{
		$sesionvars = array();
		$result = $stmt->get_result();
		$sesionvars = $result->fetch_assoc();
		$list = array("id"=>$sesionvars['id'],"lname"=>$sesionvars['lname'],"fname"=>$sesionvars['fname'],"access"=>$sesionvars['access']);
		$_SESSION['user']= $list;
		
	}
	else
	{
		unset($_SESSION['user']);
		
	}
	
	/*$stmt->bind_result($id,$fname,$lname,$access);
	if($stmt->fetch()) 
	{
		$array = array(id=>$id,fname=>$fname,lname=>$lname,access=>$access);
		$_SESSION['user']=$array;
	}*/
}
if(!isset($_SESSION['user']))
	header('Location: login.html'); // Redirect if not logged in
?>