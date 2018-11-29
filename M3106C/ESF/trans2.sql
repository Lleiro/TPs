--REMARQUE : En cas d'erreur dans une transaction, on ne peut plus rien y faire:
--on a toujours le message d'erreur suivant :
--	ERROR:  current transaction is aborted, commands ignored until end of transaction block
--Il faut donc finir par un ROLLBACK et recommencer

-- Les requetes sont a executer une par une
-- donc par des copier/coller et pas avec \i ....
-- dans l'ordre dans lequel elles sont indiquees
-- par l'utilisateur indique en commentaire

-- QUESTION 1-------------------------------------------------------------------
-- user1 fait des modifications validees, user2 des select
-- user1
begin;
-- user2
select * from COURS;
-- user1
insert into COURS values(12,'Le Centre',20,'26/12/2014','01/01/2015','14:30','16:30');
-- user2
select * from COURS;
-- user1
commit;
-- user2
select * from COURS;
-- RESULTAT : ???
-- L'user2 ne peut voir le cours 12 qu'après la fin de la transaction de l'utilisateur 1


-- QUESTION 2-------------------------------------------------------------------
-- user1 fait des modifications annulees, user2 des select
-- user1
begin;
-- user2
select * from COURS;
-- user1
insert into COURS values(13,'Le Centre',20,'01/01/2015','07/01/2015','14:30','16:30');
select * from COURS;
-- user2
select * from COURS;
-- user1
rollback;
-- user2
select * from COURS;
-- RESULTAT : ???
-- L'utilisateur2 ne peut pas voir le cours 13 puisque la transaction se termine par un ROLLBACK
-- Cependant après l'insert tant que l'utilisateur1 est dans la transaction il peut voir le cours 13

-- QUESTION 3-------------------------------------------------------------------
-- user1 et user2 insèrent des moniteurs différents (intercaler les requetes)
--user 1--
begin;
--user 2--
begin;
insert into MONITEUR values (6, 'Michelle', 'Michou', 'courchevel', '0490584525');
--user 1--
insert into MONITEUR values (5, 'Dubois', 'Gérome', 'courchevel', '0490584525');
commit;
select * from moniteur;
--user 2--
commit;
select * from moniteur;
--user 1--
select * from moniteur;

-- QU'OBSERVEZ-VOUS : ???
-- Les 2 transaction ne sont pas rentré en conflit puisqu'on ajoute 2 moniteurs différents
-- à la fin des transactions les deux moniteurs sont visibles depuis les deux utilisateurs


-- QUESTION 4-------------------------------------------------------------------
-- user1 et user2 insèrent le meme moniteur (intercaler les requetes) Cas ou user1 valide sa transaction
--user 1
begin;
insert into MONITEUR values (7, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 2
begin;
insert into MONITEUR values (7, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 1
commit;
select * from moniteur;
--user2
commit;
select * from moniteur;

-- QU'OBSERVEZ-VOUS : ???
-- Lors de l'insert du 2ème utilisateur la transaction (de l'utilisateur2) attends que la transaction de l'utilisateur1
-- soit finis pour continuer. Cela arrive uniquement si on ajoute la même clef primaire en 2 transaction intercaller
-- après le commit de l'utilisateur1 une erreur apparait pour l'utilisateur2 et donc la transaction n'est pas exécutée
-- Néanmoins le moniteur à bien été créé par l'utilisateur1.

-- user1 et user2 insèrent le meme moniteur (intercaler les requetes) Cas ou user1 annule sa transaction
--user 1
begin;
insert into MONITEUR values (8, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 2
begin;
insert into MONITEUR values (8, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 1
rollback;
select * from moniteur;
--user2
commit;
select * from moniteur;
-- QU'OBSERVEZ-VOUS : ???
-- Comme dans le cas précédent, tant que la transaction de user1 n'est pas terminé le insert de user2 est en attente
-- Après le rollback d'user1, le insert d'user2 s'exécute. Le select * from moniteur d'user 1 n'afficher rien puisque la transaction est ROLLBACK
-- à la fin de la transaction d'user2 le moniteur est crée.


-- QUESTION 5-------------------------------------------------------------------
-- user1 affecte les cours de JC Killy à Luc Alphand
--user2 les affecte a Marielle Goitschel
--user1
begin;
--user2
begin;
--user1
update ENSEIGNE set nummono='2' where numcours=1;
--user2
update ENSEIGNE set nummono='4' where numcours = 11;
--user1
update ENSEIGNE set nummono='2' where numcours = 11;
--user2
update ENSEIGNE set nummono='4' where numcours=1 ;
-- QU'OBSERVEZ-VOUS ?
-- Après le dernier update d'user2 une erreur est déclenché "ERROR: deadlock detected"
-- Le update de l'utilisateur 1 à la priorité parce qu'il a commencé la transaction en premier
--user1
commit;
--user2
commit;

-- QU'OBSERVEZ-VOUS : ???
-- Les instruction de l'user2 ont été ROLLBACK


-- QUESTION 6-------------------------------------------------------------------
-- user1 lit les informations sur les cours du Centre, user2 les retarde
--user1
begin;
select * from COURS where lieurv= 'Le Centre';
--user2
begin;
update COURS set heurefin = heurefin + interval '1 hours', heuredeb = heuredeb + interval '1 hours' where lieurv = 'Le Centre';
--user1
select * from COURS where lieurv = 'Le Centre';
-- QU'OBSERVEZ-VOUS ?
-- Les horraires chez l'utilisateur1 ne sont pas modifié car la transaction de l'utilisateur2 n'est pas finit
--user2
commit;
--user1
select * from COURS where lieurv = 'Le Centre';
-- QU'OBSERVEZ-VOUS : ???
-- Les modifications de l'users2 on été appliquer puisque sa transaction est finit
commit;

-- QUEL PROBLEME APPARAIT ICI ? POURQUOI ?
-- Il y a une lecture non reproductible puisque dans une même transaction avec deux fois la même requêtes
-- on a 2 résultats différents
