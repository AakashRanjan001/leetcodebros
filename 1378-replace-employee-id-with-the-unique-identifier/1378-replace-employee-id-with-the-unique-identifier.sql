# Write your MySQL query statement below

SELECT unique_id,name
FROM Employees as E 
Left Join 
EmployeeUNI as Eu
ON E.id = Eu.id
