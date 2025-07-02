# Write your MySQL query statement below
Select V.customer_id,Count(V.visit_id)AS count_no_trans
From
Visits as V
LEFT JOIN 
Transactions as T
ON 
V.visit_id = T.visit_id
Where T.transaction_id is NULL
GROUP BY V.customer_id