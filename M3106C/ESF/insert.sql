--------------------------------------------INSERT.SQL
set datestyle to european;

-- TYPECOURS : numtype,discipline,public,niveau
insert into typecours values(1,'alpin','enfant','piou-piou');
insert into typecours values(2,'alpin','enfant','ourson');
insert into typecours values(3,'alpin','enfant','flocon');
insert into typecours values(4,'alpin','enfant','1ère étoile');
insert into typecours values(5,'alpin','enfant','2ème étoile');
insert into typecours values(6,'alpin','enfant','3ème étoile');
insert into typecours values(7,'alpin','enfant','étoile de bronze');
insert into typecours values(8,'alpin','enfant','étoile d''or');
insert into typecours values(9,'alpin','enfant','compétition');
insert into typecours values(10,'alpin','adulte','débutant');
insert into typecours values(11,'alpin','adulte','classe 1');
insert into typecours values(12,'alpin','adulte','classe 2');
insert into typecours values(13,'alpin','adulte','classe 3');
insert into typecours values(14,'alpin','adulte','classe 4');
insert into typecours values(15,'alpin','adulte','classe 4 hors-piste');
insert into typecours values(16,'snow','tout public','débutant');
insert into typecours values(17,'snow','tout public','1er snowboard');
insert into typecours values(18,'snow','tout public','2ème snowboard');
insert into typecours values(19,'snow','tout public','3ème snowboard');
insert into typecours values(20,'snow','tout public','compétition');


--MONITEUR : nummono,nom,prenom,adresse,telephone
insert into moniteur values(1,'Killy','Jean-Claude', 'Val d''Isère','0123456789');
insert into moniteur values(2,'Alphand','Luc', 'Briançon','0123456789');
insert into moniteur values(3,'Allais','Emile', 'Courchevel','0123456789');
insert into moniteur values(4,'Goitschel','Marielle', 'Val Thorens','0123456789');

--COURS : numcours,lieuRV,numtype,datedeb, datefin,heuredeb,heurefin
insert into cours values(1,'Le Centre',1,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(2,'La Croisette',1,'26/12/2014','01/01/2015','10:00','12:00');--le meme ailleurs
insert into cours values(3,'Le Centre',2,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(4,'Le Centre',2,'26/12/2014','01/01/2015','10:00','12:00');--le meme 
insert into cours values(5,'Le Centre',3,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(6,'Le Centre',4,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(7,'Le Centre',5,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(8,'Le Centre',6,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(9,'Le Centre',7,'26/12/2014','01/01/2015','14:00','16:00');
insert into cours values(10,'Le Centre',8,'26/12/2014','01/01/2015','10:00','12:00');
insert into cours values(11,'Le Centre',8,'26/12/2014','01/01/2015','14:00','16:00');


--ENSEIGNE : nummono, numcours
insert into enseigne values(1,1);
insert into enseigne values(2,2);
insert into enseigne values(3,3);
insert into enseigne values(4,4);
insert into enseigne values(1,11);


--ELEVE : numeleve, nom, prenom, datenaissance, adressestation, mobile
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Douillet', 'David','01/01/2000','Le Pré','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Zidane','Zineddine', '01/01/2000','Le Bourg','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Manaudou' ,'Laure', '01/01/2000', 'Le Bourg','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Joubert', 'Brian', '01/01/2000', 'Le Bourg','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Noah' ,'Yannick', '01/01/2000', 'Le Bourg','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Desjoyaux', 'Michel','01/01/2000','Le Pré','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Perec' ,'Marie-José','01/01/2000','Le Pré','0123456789');
insert into eleve (nom, prenom, datenaissance, adressestation, mobile)
	values('Longo' ,'Jeannie','01/01/2000','Le Pré','0123456789');

--INSCRIT : numeleve, numcours
insert into inscrit values(1,1);
insert into inscrit values(2,1);
insert into inscrit values(3,1);
insert into inscrit values(4,2);
insert into inscrit values(5,2);
insert into inscrit values(6,2);
insert into inscrit values(6,11);
insert into inscrit values(7,3);
insert into inscrit values(7,4);



