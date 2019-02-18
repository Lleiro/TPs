--------------------
-- Exercice 2 :
--------------------


---
-- Question 1:
---
  bases3d24=> explain select code, article, name, department from towns;
                         QUERY PLAN
------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=50)
(1 row)

bases3d24=> explain select code_town, article, name_town, code_departement from all_in_one;
                           QUERY PLAN
-----------------------------------------------------------------
 Seq Scan on all_in_one  (cost=0.00..794.84 rows=36684 width=19)
(1 row)

/* Le cout de la commande de la table all_in_one semble plus important */

bases3d24=> explain analyze select code, article, name, department from towns;
                                                QUERY PLAN
-----------------------------------------------------------------------------------------------------------
 Seq Scan on towns  (cost=0.00..617.84 rows=36684 width=50) (actual time=0.014..20.559 rows=36684 loops=1)
 Planning time: 0.056 ms
 Execution time: 36.796 ms
(3 rows)

bases3d24=> explain analyze select code_town, article, name_town, code_departement from all_in_one;
                                                   QUERY PLAN
----------------------------------------------------------------------------------------------------------------
 Seq Scan on all_in_one  (cost=0.00..794.84 rows=36684 width=19) (actual time=0.061..27.900 rows=36684 loops=1)
 Planning time: 0.049 ms
 Execution time: 47.011 ms
(3 rows)

---
-- Question 2
---

bases3d24=> explain analyze select name_region, name_departement, name_town from all_in_one;
                                                   QUERY PLAN
----------------------------------------------------------------------------------------------------------------
 Seq Scan on all_in_one  (cost=0.00..794.84 rows=36684 width=34) (actual time=0.011..58.002 rows=36684 loops=1)
 Planning time: 0.045 ms
 Execution time: 89.948 ms
(3 rows)

--====---

bases3d24=> explain analyze select t.name, d.name, r.name from regions r, departments d, towns t where t.department = d.code and d.region = r.code;
                                                          QUERY PLAN
------------------------------------------------------------------------------------------------------------------------------
 Hash Join  (cost=6.21..1128.46 rows=36684 width=34) (actual time=0.541..60.741 rows=36684 loops=1)
   Hash Cond: ((t.department)::text = (d.code)::text)
   ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=15) (actual time=0.030..17.803 rows=36684 loops=1)
   ->  Hash  (cost=4.96..4.96 rows=100 width=25) (actual time=0.464..0.464 rows=100 loops=1)
         Buckets: 1024  Batches: 1  Memory Usage: 14kB
         ->  Hash Join  (cost=1.58..4.96 rows=100 width=25) (actual time=0.153..0.337 rows=100 loops=1)
               Hash Cond: ((d.region)::text = (r.code)::text)
               ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=16) (actual time=0.011..0.069 rows=100 loops=1)
               ->  Hash  (cost=1.26..1.26 rows=26 width=15) (actual time=0.072..0.073 rows=26 loops=1)
                     Buckets: 1024  Batches: 1  Memory Usage: 10kB
                     ->  Seq Scan on regions r  (cost=0.00..1.26 rows=26 width=15) (actual time=0.009..0.034 rows=26 loops=1)
 Planning time: 0.578 ms
 Execution time: 78.305 ms
(13 rows)

--====

bases3d24=> explain analyze select name_town, name_departement from all_in_one where name_region = 'Rhône-Alpes';
                                                 QUERY PLAN
-------------------------------------------------------------------------------------------------------------
 Seq Scan on all_in_one  (cost=0.00..886.55 rows=2864 width=21) (actual time=3.872..6.264 rows=2879 loops=1)
   Filter: (name_region = 'Rhône-Alpes'::text)
   Rows Removed by Filter: 33805
 Planning time: 0.072 ms
 Execution time: 7.556 ms
(5 rows)


bases3d24=> explain analyze select d.name, t.name from towns t, regions r, departments d where t.department = d.code and d.region = r.code and r.name = 'Rhône-Alpes';
                                                          QUERY PLAN
------------------------------------------------------------------------------------------------------------------------------
 Hash Join  (cost=3.80..773.88 rows=1411 width=22) (actual time=0.196..38.834 rows=2879 loops=1)
   Hash Cond: ((t.department)::text = (d.code)::text)
   ->  Seq Scan on towns t  (cost=0.00..617.84 rows=36684 width=15) (actual time=0.010..17.531 rows=36684 loops=1)
   ->  Hash  (cost=3.75..3.75 rows=4 width=13) (actual time=0.152..0.153 rows=8 loops=1)
         Buckets: 1024  Batches: 1  Memory Usage: 9kB
         ->  Hash Join  (cost=1.34..3.75 rows=4 width=13) (actual time=0.041..0.141 rows=8 loops=1)
               Hash Cond: ((d.region)::text = (r.code)::text)
               ->  Seq Scan on departments d  (cost=0.00..2.00 rows=100 width=16) (actual time=0.006..0.061 rows=100 loops=1)
               ->  Hash  (cost=1.32..1.32 rows=1 width=3) (actual time=0.016..0.016 rows=1 loops=1)
                     Buckets: 1024  Batches: 1  Memory Usage: 9kB
                     ->  Seq Scan on regions r  (cost=0.00..1.32 rows=1 width=3) (actual time=0.010..0.011 rows=1 loops=1)
                           Filter: (name = 'Rhône-Alpes'::text)
                           Rows Removed by Filter: 25
 Planning time: 0.416 ms
 Execution time: 40.225 ms
(15 rows)


--------------------
-- Exercice 3 :
--------------------

---
-- Question 1 :
---
bases3d24=> explain analyze insert into towns values (36685,1987,'','GRELYON',38);
                                           QUERY PLAN
-------------------------------------------------------------------------------------------------
 Insert on towns  (cost=0.00..0.01 rows=1 width=126) (actual time=66.164..66.164 rows=0 loops=1)
   ->  Result  (cost=0.00..0.01 rows=1 width=126) (actual time=0.001..0.002 rows=1 loops=1)
 Planning time: 4.517 ms
 Trigger for constraint towns_department_fkey: time=91.489 calls=1
 Execution time: 157.696 ms
(5 rows)

bases3d24=> explain analyze insert into all_in_one (code_town, article, name_town) VALUES(1987,'','GRELYON');
ERROR:  null value in column "code_region" violates not-null constraint
DETAIL:  Failing row contains (36685, null, null, null, null, null, null, 1987, , GRELYON).
bases3d24=>


---Question 2
bases3d24=> explain analyze update all_in_one set name_region = 'AURA' WHERE name_region='Rhône-Alpes';
                                                     QUERY PLAN
---------------------------------------------------------------------------------------------------------------------
 Update on all_in_one  (cost=0.00..886.55 rows=2864 width=85) (actual time=48.626..48.626 rows=0 loops=1)
   ->  Seq Scan on all_in_one  (cost=0.00..886.55 rows=2864 width=85) (actual time=10.418..14.994 rows=2879 loops=1)
         Filter: (name_region = 'Rhône-Alpes'::text)
         Rows Removed by Filter: 33805
 Planning time: 0.098 ms
 Execution time: 48.691 ms
(6 rows)

bases3d24=> explain analyze update regions set name = 'AURA' where name = 'Rhône-Alpes';
                                               QUERY PLAN
--------------------------------------------------------------------------------------------------------
 Update on regions  (cost=0.00..1.32 rows=1 width=51) (actual time=12.368..12.368 rows=0 loops=1)
   ->  Seq Scan on regions  (cost=0.00..1.32 rows=1 width=51) (actual time=0.068..0.074 rows=1 loops=1)
         Filter: (name = 'Rhône-Alpes'::text)
         Rows Removed by Filter: 25
 Planning time: 0.234 ms
 Execution time: 12.436 ms
(6 rows)

bases3d24=> explain analyze update regions set capital = 690123 where name = 'Aura';
                                               QUERY PLAN
--------------------------------------------------------------------------------------------------------
 Update on regions  (cost=0.00..1.32 rows=1 width=63) (actual time=0.112..0.112 rows=0 loops=1)
   ->  Seq Scan on regions  (cost=0.00..1.32 rows=1 width=63) (actual time=0.110..0.110 rows=0 loops=1)
         Filter: (name = 'Aura'::text)
         Rows Removed by Filter: 26
 Planning time: 0.115 ms
 Execution time: 0.146 ms
(6 rows)

bases3d24=> explain analyze update all_in_one set capital_region = 690123 where name_region = 'AURA';
                                                   QUERY PLAN
----------------------------------------------------------------------------------------------------------------
 Update on all_in_one  (cost=0.00..946.62 rows=1 width=98) (actual time=21.630..21.630 rows=0 loops=1)
   ->  Seq Scan on all_in_one  (cost=0.00..946.62 rows=1 width=98) (actual time=4.470..7.636 rows=2879 loops=1)
         Filter: (name_region = 'AURA'::text)
         Rows Removed by Filter: 33805
 Planning time: 0.102 ms
 Execution time: 21.671 ms
(6 rows)

/* Les mises à jours sont plus rapide sur la table de base que all_in_one */



----
---Question 3
----
bases3d24=> explain analyze delete from towns where name = 'Grelyon';
                                              QUERY PLAN
-------------------------------------------------------------------------------------------------------
 Delete on towns  (cost=0.00..709.55 rows=1 width=6) (actual time=8.878..8.879 rows=0 loops=1)
   ->  Seq Scan on towns  (cost=0.00..709.55 rows=1 width=6) (actual time=8.875..8.875 rows=0 loops=1)
         Filter: (name = 'Grelyon'::text)
         Rows Removed by Filter: 36685
 Planning time: 0.102 ms
 Execution time: 8.903 ms
(6 rows)

bases3d24=> explain analyze delete from all_in_one where name_town = 'Grelyon';
                                                 QUERY PLAN
------------------------------------------------------------------------------------------------------------
 Delete on all_in_one  (cost=0.00..946.62 rows=1 width=6) (actual time=7.355..7.356 rows=0 loops=1)
   ->  Seq Scan on all_in_one  (cost=0.00..946.62 rows=1 width=6) (actual time=7.351..7.352 rows=0 loops=1)
         Filter: (name_town = 'Grelyon'::text)
         Rows Removed by Filter: 36684
 Planning time: 0.081 ms
 Execution time: 7.380 ms
(6 rows)


/* L'éxecution se fait plus rapidemement sur la table all in one */
