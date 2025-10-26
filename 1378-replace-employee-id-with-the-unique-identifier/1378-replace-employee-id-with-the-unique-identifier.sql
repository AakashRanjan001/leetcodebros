SELECT unique_id, name
FROM Employees as e
LEFT JOIN EmployeeUNI as e1
ON e.id = e1.id;
