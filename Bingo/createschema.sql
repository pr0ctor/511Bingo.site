drop table Users;
drop table Items;
drop table Cards;

create table users
(
	id bigint auto_increment unique,
	username varchar(50) unique,
	password blob,
	creation_date timestamp,
	role varchar(100) default 'User',
	primary key(id),
	foreign key(role) references roles(role)
);

create table items
(
	id bigint auto_increment unique,
	content TEXT,
	primary key(id)
);

create table cards
(
	cardid bigint auto_increment unique,
	userid bigint,
	carddata blob,
	foreign key(userid) references users(id),
	primary key(cardid)
	
);

create table roles
(
	role varchar(100) unique,
	primary key(role)
);

INSERT INTO roles VALUES("Admin");
INSERT INTO roles VALUES("User");
INSERT INTO roles VALUES("Caller");