-- -- # Write your MySQL query statement below
-- -- SELECT S.user_id, 
-- --        IFNULL(ROUND(SUM(C.action = 'confirmed') / COUNT(C.user_id),0),2) as confirmation_rate
-- -- FROM
-- -- Signups as S
-- -- LEFT JOIN 
-- -- Confirmations as C
-- -- ON S.user_id = C.user_id


-- SELECT S.user_id,
--        ROUND(
--          IFNULL(SUM(C.action = 'confirmed') / COUNT(C.user_id), 0),
--          2
--        ) AS confirmation_rate
-- FROM Signups AS S
-- LEFT JOIN Confirmations AS C
--        ON S.user_id = C.user_id
-- GROUP BY S.user_id;

# Write your MySQL query statement below
select s.user_id, round(avg(if(c.action="confirmed",1,0)),2) as confirmation_rate
from Signups as s left join Confirmations as c on s.user_id= c.user_id group by user_id;


