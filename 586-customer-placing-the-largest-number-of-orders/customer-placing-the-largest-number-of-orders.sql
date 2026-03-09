# Write your MySQL query statement below
SELECT customer_number
FROM (
    SELECT customer_number, Count(*) as cnt
    FROM Orders
    GROUP BY customer_number
    ORDER BY cnt DESC
) t
LIMIT 1;