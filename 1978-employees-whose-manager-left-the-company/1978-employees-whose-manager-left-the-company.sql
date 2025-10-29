# Write your MySQL query statement below

SELECT e1.employee_id
 FROM Employees  as e1 
  LEFT JOIN 
      Employees as e2
      ON e1.manager_id = e2.employee_id

   where e1.salary<30000 AND e1.manager_id is NOT NULL AND  e2.employee_id is NULL
   ORDER BY e1.employee_id;
  
