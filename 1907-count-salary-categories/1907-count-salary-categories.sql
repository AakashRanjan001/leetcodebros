# Write your MySQL query statement below
SELECT 
    "Low Salary" as category,
    COUNT(income) as accounts_count

    FROM Accounts
    where income<20000
UNION 
SELECT 
    "Average Salary" as category,
    COUNT(income) as accounts_count

    FROM Accounts
    where income>=20000 AND income<=50000
UNION
SELECT
    "High Salary" as category,
    COUNT(income) as accounts_count

    FROM Accounts
    where income>50000

