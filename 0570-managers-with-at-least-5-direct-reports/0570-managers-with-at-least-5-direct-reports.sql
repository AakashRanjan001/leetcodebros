# Write your MySQL query statement below
Select e1.name 
From
Employee as e1
 JOIN
Employee  e2
ON e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(*)>=5
