SELECT E.name , B.bonus
FROM Employee as E
LEFT JOIN 
Bonus as B
ON E.empId = B.empId
WHERE 
  B.bonus < 1000 OR B.bonus is NULL;