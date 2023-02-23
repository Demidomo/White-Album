show databases;
use sakila;
show tables like '%customer%';
desc customer;
+-------------+----------------------+------+-----+---------------------+-------------------------------+
| Field       | Type                 | Null | Key | Default             | Extra                         |
+-------------+----------------------+------+-----+---------------------+-------------------------------+
| customer_id | smallint(5) unsigned | NO   | PRI | NULL                | auto_increment                |
| store_id    | tinyint(3) unsigned  | NO   | MUL | NULL                |                               |
| first_name  | varchar(45)          | NO   |     | NULL                |                               |
| last_name   | varchar(45)          | NO   | MUL | NULL                |                               |
| email       | varchar(50)          | YES  |     | NULL                |                               |
| address_id  | smallint(5) unsigned | NO   | MUL | NULL                |                               |
| active      | tinyint(1)           | NO   |     | 1                   |                               |
| create_date | datetime             | NO   |     | NULL                |                               |
| last_update | timestamp            | NO   |     | current_timestamp() | on update current_timestamp() |
+-------------+----------------------+------+-----+---------------------+-------------------------------+


SELECT first_name, last_name email
    -> from customer;
    


SELECT first_name, last_name, email FROM customer LIMIT 5;
+------------+-----------+-------------------------------------+
| first_name | last_name | email                               |
+------------+-----------+-------------------------------------+
| MARY       | SMITH     | MARY.SMITH@sakilacustomer.org       |
| PATRICIA   | JOHNSON   | PATRICIA.JOHNSON@sakilacustomer.org |
| LINDA      | WILLIAMS  | LINDA.WILLIAMS@sakilacustomer.org   |
| BARBARA    | JONES     | BARBARA.JONES@sakilacustomer.org    |
| ELIZABETH  | BROWN     | ELIZABETH.BROWN@sakilacustomer.org  |
+------------+-----------+-------------------------------------+
 
desc film;
+----------------------+---------------------------------------------------------------------+------+-----+---------------------+-------------------------------+
| Field                | Type                                                                | Null | Key | Default             | Extra                         |
+----------------------+---------------------------------------------------------------------+------+-----+---------------------+-------------------------------+
| film_id              | smallint(5) unsigned                                                | NO   | PRI | NULL                | auto_increment                |
| title                | varchar(128)                                                        | NO   | MUL | NULL                |                               |
| description          | text                                                                | YES  |     | NULL                |                               |
| release_year         | year(4)                                                             | YES  |     | NULL                |                               |
| language_id          | tinyint(3) unsigned                                                 | NO   | MUL | NULL                |                               |
| original_language_id | tinyint(3) unsigned                                                 | YES  | MUL | NULL                |                               |
| rental_duration      | tinyint(3) unsigned                                                 | NO   |     | 3                   |                               |
| rental_rate          | decimal(4,2)                                                        | NO   |     | 4.99                |                               |
| length               | smallint(5) unsigned                                                | YES  |     | NULL                |                               |
| replacement_cost     | decimal(5,2)                                                        | NO   |     | 19.99               |                               |
| rating               | enum('G','PG','PG-13','R','NC-17')                                  | YES  |     | G                   |                               |
| special_features     | set('Trailers','Commentaries','Deleted Scenes','Behind the Scenes') | YES  |     | NULL                |                               |
| last_update          | timestamp                                                           | NO   |     | current_timestamp() | on update current_timestamp() |
+----------------------+--


 select distinct(rental_rate) FROM film;
+-------------+
| rental_rate |
+-------------+
|        0.99 |
|        4.99 |
|        2.99 |

SELECT title, release_year, length FROM film WHERE length BETWEEN 50 and 60 AND rental_rate = 2.99 ORDER BY TITLE;
+--------------------+--------------+--------+
| title              | release_year | length |
+--------------------+--------------+--------+
| ADAPTATION HOLES   |         2006 |     50 |
| BLUES INSTINCT     |         2006 |     50 |
| CRANES RESERVOIR   |         2006 |     57 |
| CUPBOARD SINNERS   |         2006 |     56 |
| DOCTOR GRAIL       |         2006 |     57 |
| JEKYLL FROGMEN     |         2006 |     58 |
| LUST LOCK          |         2006 |     52 |
| MAGNIFICENT CHITTY |         2006 |     53 |
| NOON PAPI          |         2006 |     57 |
| PHANTOM GLORY      |         2006 |     60 |
| PILOT HOOSIERS     |         2006 |     50 |
| SHAKESPEARE SADDLE |         2006 |     60 |
| SMILE EARRING      |         2006 |     60 |
| TROJAN TOMORROW    |         2006 |     52 |
+--------------------+--------------+--------+



SELECT COUNT(*)
    FROM film
        WHERE length <= 30
        AND rental_rate = 4.99;


+----------+
| COUNT(*) |
+----------+
|        0 |
+----------+
1 row in set (0.001 sec)


-- 
-- SELECT title, release_year, length
--     FROM film
--         WHERE length BETWEEN 50 and 60
--             AND rental_rate = 2.99
--             ORDER BY title;


-- The number of films where the lenght is at least less than or equal to 30 minutes 
-- and the rental rate is 4.99

SELECT COUNT(*)
    FROM film
        WHERE length >= 30
        AND rental_rate = 4.99;



-- the title, rental rate, for all movies that are rated "R" or "G"
-- that include deleted scenes, order by the most expensive rental first 

-- SELECT title, rental_rate, rating, special_features
--     FROM film
--         WHERE rating IN ('R', 'G')
--             AND special_features IN ('Deleted Scenes')
--             ORDER BY rental_rate DESC; 



-- SELECT title, first_name, last_name
--     FROM film, film_actor, actor
--         WHERE film.film_id = film_actor.film_id
--             AND film_actor.actor_id = actor.actor_id
--             AND title = "Polish Brooklyn"
--             ORDER by last_name, first_name;    -- alphabetical order



-- SELECT * FROM film_actor WHERE film_id = 688;


-- SELECT * FROM actor WHERE actor_id = 14;

-- SELECT * FROM actor WHERE actor_id = 22;


-- SELECT title, first_name, last_name
--     FROM  film, film_actor, actor
--      WHERE film.film_id = film_actor.film_id
--         AND film_actor.actor_id = actor.actor_id
--         AND  first_name = 'VIVIEN'
--         AND last_name = 'BERGEN';
       




