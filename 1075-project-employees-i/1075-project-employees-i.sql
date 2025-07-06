-- ✅ Approach 1: Using CAST to Decimal
SELECT 
    p.project_id,
    ROUND(AVG(CAST(e.experience_years AS DECIMAL(10,2))), 2)
 AS average_years
FROM 
    Project p
INNER JOIN 
    Employee e ON p.employee_id = e.employee_id
GROUP BY 
    p.project_id;
 