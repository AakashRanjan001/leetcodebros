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


SELECT currentDay.id
 FROM Weather as CurrentDay
 where EXISTS (
         SELECT * 
         FROM Weather as yesterday
         WHERE currentDay.temperature > yesterday.temperature
         AND currentDay.recordDate = yesterday.recordDate +INTERVAL 1 DAY 
 );


