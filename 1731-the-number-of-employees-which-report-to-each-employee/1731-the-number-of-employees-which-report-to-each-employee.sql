-- # Write your MySQL query statement below
-- SELECT E1.employee_id ,E1.name, COUNT(E2.reports_to) as reports_count, ROUND(AVG(E2.age),0)as average_age
--  FROM 
--  Employees as E1
--   JOIN
-- Employees as E2

-- ON
-- E1.employee_id = E2.reports_to
-- WHERE E1.reports_to is NULL
-- GROUP BY E1.employee_id,E1.name
-- ORDER BY E1.employee_id;
# Write your MySQL query statement below
SELECT 
    E1.employee_id,
    E1.name,
    COUNT(E2.employee_id) AS reports_count,
    ROUND(AVG(E2.age), 0) AS average_age
FROM 
    Employees AS E1
JOIN 
    Employees AS E2
ON 
    E1.employee_id = E2.reports_to
GROUP BY 
    E1.employee_id, E1.name
ORDER BY 
    E1.employee_id;
