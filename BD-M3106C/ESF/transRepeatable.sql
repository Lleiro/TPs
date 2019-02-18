-- QUESTION 1-------------------------------------------------------------------
-- user1 fait des modifications validees, user2 des select
-- user1
begin;
set transaction isolation level repeatable read ;
-- user2
select * from COURS;
-- user1
insert into COURS values(13,'Le Centre',20,'26/12/2014','01/01/2015','14:30','16:30');
-- user2
select * from COURS;
-- user1
commit;
-- user2
select * from COURS;
-- RESULTAT : ???
-- Il se passe la même chose que sans le set transaction c'est à dire que
-- L'user2 ne peut voir le cours 12 qu'après la fin de la transaction de l'utilisateur 1


-- QUESTION 2-------------------------------------------------------------------
-- user1 fait des modifications annulees, user2 des select
-- user1
begin;
set transaction isolation level repeatable read ;
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
-- Il se passe la même chose  sans le set transaction c'est à dire que
-- L'utilisateur2 ne peut pas voir le cours 13 puisque la transaction se termine par un ROLLBACK
-- Cependant après l'insert tant que l'utilisateur1 est dans la transaction il peut voir le cours 13



-------
-- Pour la question 3 Il n'y a pas changement
-------

-- QUESTION 4-------------------------------------------------------------------
-- user1 et user2 insèrent le meme moniteur (intercaler les requetes) Cas ou user1 valide sa transaction
--user 1
begin;
set transaction isolation level repeatable read ;
insert into MONITEUR values (9, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 2
begin;
set transaction isolation level repeatable read ;
insert into MONITEUR values (9, 'Richard', 'Martin', 'courchevel', '0490584525');
--user 1
commit;
select * from moniteur;
--user2
commit;
select * from moniteur;

-- QU'OBSERVEZ-VOUS : ???
-- Le problème ne change pas, on peut observer la même chose sans le set transaction

-------
-- Pour la question 5 Il n'y a pas changement non plus
-------



-- QUESTION 6-------------------------------------------------------------------
-- user1 lit les informations sur les cours du Centre, user2 les retarde
--user1
begin;
set transaction isolation level repeatable read ;
select * from COURS where lieurv= 'Le Centre';
--user2
begin;
set transaction isolation level repeatable read ;
update COURS set heurefin = heurefin + interval '1 hours', heuredeb = heuredeb + interval '1 hours' where lieurv = 'Le Centre';
--user1
select * from COURS where lieurv = 'Le Centre';
-- QU'OBSERVEZ-VOUS ?
-- Les horraires de l'utilisateur1 ne sont pas modifié
--user2
commit;
--user1
select * from COURS where lieurv = 'Le Centre';
-- QU'OBSERVEZ-VOUS : ???
-- Les modifications n'ont toujours pas été effectuer
commit;
--user1
select * from COURS where lieurv = 'Le Centre';
-- QU'OBSERVEZ-VOUS : ???
-- après le commit de l'user1 les modifications ont été effectuées;


-- QUEL PROBLEME APPARAIT ICI ? POURQUOI ?
-- Il y a une lecture non reproductible puisque dans une même transaction avec deux fois la même requêtes
-- on a 2 résultats différents
