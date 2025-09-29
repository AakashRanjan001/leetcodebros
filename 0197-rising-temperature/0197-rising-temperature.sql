-- # Write your MySQL query statement below
-- -- this is a good question 
-- -- OUTER QUERY will have an eye on the current date and 
-- -- INNER QUERY will have an eye on previos date (yesterday to be specific)

-- Select Today.id from Weather as Today
-- WHERE EXISTS

--      -- NESTED QUERY returns true or false
--     ( SELECT 1 FROM Weather as Yesterday
--      WHERE 
--      Yesterday.temperature < Today.temperature
--      AND
--      Today.recordDate - Yesterday.recordDate = 1)


SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;