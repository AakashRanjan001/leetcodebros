# Write your MySQL query statement below
-- can be solved using subqueis 
-- can be solved using functions that is LIMIT OFFSET
 -- can be solved using JOIN S

SELECT MAX(e1.salary) as SecondHighestSalary
 FROM Employee as e1 INNER JOIN Employee as e2
 ON e1.salary<e2.salary;