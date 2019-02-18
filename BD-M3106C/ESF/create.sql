--------------------------------------------CREATE.SQL
create table typecours(
numtype numeric(2) primary key,
discipline varchar(10) check (discipline in ('alpin', 'snow')),
public varchar(11) check (public in ('adulte','enfant','tout public')),
niveau varchar(20));

create table moniteur(
nummono numeric(2) primary key,
nom varchar(15) not null,
prenom varchar(15),
adresse varchar(20),
telephone char(10));

create table cours(
numcours numeric(2) primary key,
lieuRV varchar(15) check (lieuRV in ('Le Centre', 'La Croisette', 'La Chaudanne')),
numtype numeric (2) references typecours(numtype),
datedeb date,
datefin date,
heuredeb time,
heurefin time,
check (heurefin-heuredeb='02:00'));

create table enseigne
(nummono numeric(2) references moniteur(nummono),
numcours numeric(2) references cours(numcours) primary key);

create table eleve(
numeleve serial primary key,
nom varchar(15),
prenom varchar(15),
datenaissance date,
adressestation varchar(20),
mobile char(10));

create table inscrit (
numeleve integer references eleve (numeleve),
numcours numeric(2) references cours(numcours),
primary key (numeleve, numcours));
