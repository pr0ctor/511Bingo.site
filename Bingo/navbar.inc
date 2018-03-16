<div>
<p align="Center">
<a href="index.html">Home</a> 
<?php
if(!empty($_SESSION['user']))
{
	?>
	| <a href="account.html">My Account</a> | <a href="card.html">My Card</a>

<?php
	}
	else
	{
	
?>
	| <a href="login.html">Login</a> | <a href="register.html">Register</a>

<?php
	}
?>	
</p>
</div>