STEP 1: How to create a table
CREATE TABLE groceries(name TEXT, quantity INTEGER);
//we need unique ID for each row and col so we specify it here again


CREATE TABLE groceries(id INTEGER PRIMARY KEY, name TEXT, quantity INTEGER, aisle INTEGER);

INSERT INTO groceries VALUES(1,"Bananas",4,7);
INSERT INTO groceries VALUES(2,"Peanut Butter",1,2);
INSERT INTO groceries VALUES(3,"Chocolate Butter",2,7);
INSERT INTO groceries VALUES(4,"Ice cream",4,12);
INSERT INTO groceries VALUES(5,"Peanut Cream",1,2);
INSERT INTO groceries VALUES(6,"Chocolate syrup",2,4);

////////////////////////////////////////////update as well, add constraint, add col, delete, truncate, can change data type

SELECT * FROM groceries

STEP 2: How to query

SELECT name FROM groceries; //lists just the name out of order
SELECT * FROM groceries ORDER BY aisle;

//filter results:
SELECT * FROM groceries WHERE aisle>5 ORDER BY aisle;

//aggregate function is helpful to get max,min and sum

SELECT MAX(quantity) FROM groceries; 
SELECT SUM(quantity) FROM groceries; 

//SUM is an aggregate function here which returns the total items 14

SELECT aisle, SUM(quantity) FROM groceries GROUP BY aisle; => this aisle should be always present next to the select clause

//shouldnt use something different than what you are grouping by

aisle 			SUM
2				9
4				1
7				56
12				1





// auto generating IDS
CREATE TABLE groceries(id INTEGER PRIMARY KEY AUTOINCREMENT
, name TEXT, quantity INTEGER, aisle INTEGER);

INSERT INTO groceries(name,quantity,aisle) VALUES("Bananas",4,7);
INSERT INTO groceries(name,quantity,aisle) VALUES("Peanut Butter",1,2);
INSERT INTO groceries(name,quantity,aisle) VALUES("Chocolate Butter",2,7);
INSERT INTO groceries(name,quantity,aisle) VALUES("Ice cream",4,12);
INSERT INTO groceries(name,quantity,aisle) VALUES("Peanut Cream",1,2);
INSERT INTO groceries(name,quantity,aisle) VALUES("Chocolate syrup",2,4);

SELECT * FROM groceries WHERE aisle>5 ORDER BY quantity;
SELECT * FROM groceries WHERE aisle>5 AND aisle<10 ORDER BY quantity;
SELECT * FROM groceries WHERE aisle>5 OR aisle<10 ORDER BY quantity;


//here is another example where OR is useful but replaced by a shorted query

SELECT * FROM groceries WHERE name="Bananas" OR name = "Peanut" OR name = "Chocolate syrup";

SELECT * FROM groceries WHERE name IN ("Bananas","Peanut","Chocolate syrup";

SELECT * FROM groceries WHERE name NOT IN ("Bananas","Peanut","Chocolate syrup";

//Suppose we have another table with name tejans_favorite
SELECT name FROM tejans_favorite;

SELECT * FROM groceries WHERE type IN(SELECT name FROM tejans_favorite);

// here we are using like to do inexact query;
SELECT * FROM groceries WHERE type IN(SELECT name FROM tejans_favorite WHERE name LIKE "chocolate");


// we use AS operation to specify table name;
SELECT aisle, SUM(quantity) AS total_sum FROM groceries GROUP BY aisle;

//using HAVING instead of WHERE. In this case we look across all logs

SELECT aisle, SUM(quantity) AS total_sum,
	CASE
		WHEN quantity > 5 THEN "above five"
		WHEN quantity > ROUND(4.5) THEN "above round 4.5"
		ELSE "below target"
	END as "zone"
FROM groceries GROUP BY zone;