# Write your MySQL query statement below
 -- we will use the case expression as we will see in the case of query 

 SELECT 
    CASE 
        WHEN 
          -- last wala case jab id last wala bachh jaat hai
           id = (SELECT MAX(id) FROM Seat) AND MOD(id,2) = 1
           THEN id
        WHEN   
            MOD(id , 2) = 1 
            THEN id + 1
        ELSE 
            id - 1
    END as id ,student
    FROM Seat
    ORDER BY id
        