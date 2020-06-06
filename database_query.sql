DROP DATABASE IF EXISTS accounting_db;
CREATE DATABASE accounting_db;
USE accounting_db;

CREATE TABLE IF NOT EXISTS Expenses(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    type ENUM ('transport', 'electricity', 'water', 'heating', 'rent', 'food', 'taxes',  'clothes') NOT NULL,
    cost DOUBLE NOT NULL, 
    date DATE NOT NULL
);

INSERT INTO Expenses(type, cost, date) VALUES 
	(1, 21.2, '2020-05-21'),
	(2, 35.2, '2020-05-21'),
	(3, 40.2, '2020-05-21'),
	(4, 130.2, '2020-05-21'),
	(5, 220.2, '2020-05-21'),
	(6, 300.2, '2020-05-21'),
	(7, 33.2, '2020-05-21'),
	(8, 67.2, '2020-05-21');

SELECT * FROM Expenses;
