# Write your MySQL query statement below
SELECT DISTINCT customer_id , COUNT(customer_id) as count_no_trans
FROM Visits as V
LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id
where T.transaction_id is NULL
GROUP BY  V.customer_id;