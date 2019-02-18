--------------------------------------------TRANS1.SQL

------------------------------
-- EXERCICE 1
------------------------------
BEGIN; -- Début de la transaction
insert into MONITEUR values (10, 'lacroix', 'franck', 'courchevel', '0490584525');
select * from MONITEUR where nummono = 10;
ROLLBACK; -- Le ROLLBACK va supprimer toutes les transaction jusqu'au BEGIN
select * from MONITEUR where nummono = 10; -- Rien est ajouté à la table à cause du rollback


BEGIN; -- Début de la transaction
insert into MONITEUR values (10, 'lacroix', 'franck', 'courchevel', '0490584525');
select * from MONITEUR where nummono = 10;
COMMIT; -- Tout se passe bien, le insert est bien effectuer dans la table MONITEUR
select * from MONITEUR where nummono = 10; -- Le MONITEUR nummono 10 à bien été créé dans la table

------------------------------
-- EXERCICE 2
------------------------------
BEGIN;-- Début de la transaction
insert into MONITEUR values (null, 'lapierre', 'ecric', 'chamrousse', '0490584525'); -- On insère la valeur null dans nummono cela déclenche une erreur
select * from MONITEUR; -- la requête est ignorée puisqu'une erreur à été déclenché plus tôt dans le bloc de transaction
COMMIT; -- La transaction n'est pas exécuter à cause de l'erreur dans le insert
select * from MONITEUR;

BEGIN;-- Début de la transaction
insert  into ELEVE(nom,  prenom,  datenaissance,  adressestation, mobile)
      values  ('gigi', 'lebronze', '05/12/1971', 'sur le télésiège', '0789889988');
select * from ELEVE;
insert into INSCRIT values('gigi',1);
  -- Il y a une erreur à cause du insert into INSCRIT (le premier élement de la table doit être un integer)
COMMIT; -- La transaction n'est pas exécuter à cause du insert into INSCRIT
SELECT * from ELEVE; -- Rien est ajouté à la table puisque le bloc ne s'est pas exécuter correctement
SELECT * from INSCRIT; -- idem

-- l'intérêt d'utiliser des transaction est d'exécuter une ou plusieurs commande en un seul bloc
-- pour que d'autres requêtes ne puissent pas interférer avec ce que l'on souhaite faire sur la base


------------------------------
-- EXERCICE 3
------------------------------

----
-- Question 1 et 2
----
