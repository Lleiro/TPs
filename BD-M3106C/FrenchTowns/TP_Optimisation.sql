Exercice 1

Question 1 :
Cette commande affiche plein d''information sur les relations de la BD.

Le catalogue pg_class liste les tables, les index, les séquences, les vues, les types composites et les tables TOAST.
relpages indique une éstimation de la taille en page du fichier sur le disque.
reltuples indique une éstimation du nombre de ligne d''une table.


departments :  1 100
departments_capital_key: 2 100
departments_code_key: 2 100
departments_id_key: 2 100
departments_id_seq: 1 1
departments_name_key: 2 100
towns: 251 36684
towns_id_key: 103 36684
towns_id_seq: 1 1
towns_code_department_key: 133 36684
regions: 0 0
regions_code_key: 1 0
regions_id_key: 1 0
regions_id_seq: 1 1
regions_name_key: 2 26

-------------------------------------------

Question 2:
ANALYZE collecte des statistiques sur le contenu des tables de la base de données et stocke les résultats dans le catalogue système pg_statistic.

region : 1 26
region_code_key : 2 26
region_id_key : 2 26

-------------------------------------------





Exercice 2


Question 1:

 explain select * from towns;
                         QUERY PLAN
------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=54)
(1 row)





explain analyze select * from towns;


                                                QUERY PLAN
-----------------------------------------------------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=54) (actual time=0.012..17.529 rows=36684 loops=1)
 Planning time: 0.049 ms
 Execution time: 33.490 ms


Recherche séquentielle.
Les coûts représentent les coûts possible de cette requête.



------------------------------------------------------------

Question 2:

1)
select code,name from towns;

                         QUERY PLAN
------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=15)



2)
select region, department, t.name from towns t, regions r, departments d where t.department=d.code and d.region=r.code;

                                    QUERY PLAN
----------------------------------------------------------------------------------
 Hash Join  (cost=6.21..1128.46 rows=36684 width=18)
   Hash Cond: ((t.department)::text = (d.code)::text)
   ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=15)
   ->  Hash  (cost=4.96..4.96 rows=100 width=6)
         ->  Hash Join  (cost=1.58..4.96 rows=100 width=6)
               Hash Cond: ((d.region)::text = (r.code)::text)
               ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=6)
               ->  Hash  (cost=1.26..1.26 rows=26 width=3)
                     ->  Seq Scan on regions r  (cost=0.00..1.26 rows=26 width=3)



3)

select t.name, d.name from towns t, departments d, regions r where r.name ='Rhône-Alpes' and r.code = d.region and d.code = t.department;
                                    QUERY PLAN
----------------------------------------------------------------------------------
 Hash Join  (cost=3.80..773.88 rows=1411 width=22)
   Hash Cond: ((t.department)::text = (d.code)::text)
   ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=15)
   ->  Hash  (cost=3.75..3.75 rows=4 width=13)
         ->  Hash Join  (cost=1.34..3.75 rows=4 width=13)
               Hash Cond: ((d.region)::text = (r.code)::text)
               ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=16)
               ->  Hash  (cost=1.32..1.32 rows=1 width=3)
                     ->  Seq Scan on regions r  (cost=0.00..1.32 rows=1 width=3)
                           Filter: (name = 'Rhône-Alpes'::text)


4)
-- select t.name, d.name from (select code from regions where name='Rhône-Alpes') as r, departments d, towns t where d.region = r.code and t.department = d.code;
-- select t.name, d.name from (select d.code, d.name from departments d, regions r where d.region = r.code and r.name='Rhône-Alpes') as d, towns t where t.department = d.code;
select t.name, d.name from departments d, towns t where d.region in (select code from regions where name='Rhône-Alpes') and t.department = d.code;


                                    QUERY PLAN
----------------------------------------------------------------------------------
 Hash Join  (cost=3.69..773.77 rows=1411 width=22)
   Hash Cond: ((t.department)::text = (d.code)::text)
   ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=15)
   ->  Hash  (cost=3.64..3.64 rows=4 width=13)
         ->  Hash Semi Join  (cost=1.34..3.64 rows=4 width=13)
               Hash Cond: ((d.region)::text = (regions.code)::text)
               ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=16)
               ->  Hash  (cost=1.32..1.32 rows=1 width=3)
                     ->  Seq Scan on regions  (cost=0.00..1.32 rows=1 width=3)
                           Filter: (name = 'Rhône-Alpes'::text)


5)

select count (*) from towns;

                           QUERY PLAN
-----------------------------------------------------------------
 Aggregate  (cost=709.55..709.56 rows=1 width=8)
   ->  Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=0)


Coût de 709.55..709.56 alors que dans la question 1 le coût était de 0.00..617.84;


6)
select department, count(*) from towns t group by department order by department;
                                      QUERY PLAN
---------------------------------------------------------------------------------------
 Sort  (cost=64821.41..64821.66 rows=100 width=11)
   Sort Key: t.department
   ->  HashAggregate  (cost=64817.09..64818.09 rows=100 width=11)
         Group Key: t.department
         ->  Nested Loop  (cost=0.00..46475.09 rows=3668400 width=3)
               ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=3)
               ->  Materialize  (cost=0.00..2.50 rows=100 width=0)
                     ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=0)



7)
select region, count(*) from departments group by region;
                            QUERY PLAN
-------------------------------------------------------------------
 HashAggregate  (cost=2.50..2.76 rows=26 width=11)
   Group Key: region
   ->  Seq Scan on departments  (cost=0.00..2.00 rows=100 width=3)




8)
select region, count(*) from departments group by region having count(*) >5;
                            QUERY PLAN
-------------------------------------------------------------------
 HashAggregate  (cost=2.75..3.01 rows=26 width=11)
   Group Key: region
   Filter: (count(*) > 5)
   ->  Seq Scan on departments  (cost=0.00..2.00 rows=100 width=3)

Cette instruction est plus longue que la 7) (car traitement supplémentaire).



Exercice 3:

Question 1:
bases3d24=> explain analyze select * from towns where name = 'Grenoble';
                                            QUERY PLAN
--------------------------------------------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..709.55 rows=1 width=54) (actual time=2.023..4.861 rows=1 loops=1)
   Filter: (name = 'Grenoble'::text)
   Rows Removed by Filter: 36683
 Planning time: 0.112 ms
 Execution time: 4.891 ms
(5 rows)

bases3d24=> Create index towns_index on TOWNS(name);
CREATE INDEX


bases3d24=> explain analyze select * from towns where name = 'Grenoble';
                                                     QUERY PLAN
--------------------------------------------------------------------------------------------------------------------
 Index Scan using towns_index on towns  (cost=0.29..8.31 rows=1 width=54) (actual time=0.020..0.021 rows=1 loops=1)
   Index Cond: (name = 'Grenoble'::text)
 Planning time: 0.105 ms
 Execution time: 0.042 ms
(4 rows)

/* Le temps de l'execution après la création de l'index est beaucoup plus rapide ( 100* moins long) */

bases3d24=> Create index towns_index2 on TOWNS(name,department);
CREATE INDEX

bases3d24=> explain analyze select * from towns where name = 'Grenoble';
                                                     QUERY PLAN
---------------------------------------------------------------------------------------------------------------------
 Index Scan using towns_index2 on towns  (cost=0.29..8.31 rows=1 width=54) (actual time=0.090..0.091 rows=1 loops=1)
   Index Cond: (name = 'Grenoble'::text)
 Planning time: 0.241 ms
 Execution time: 0.113 ms
(4 rows)
