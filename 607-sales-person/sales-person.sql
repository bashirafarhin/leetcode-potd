# Write your MySQL query statement below

SELECT name
FROM salesperson
WHERE name NOT IN (
    SELECT s.name
FROM salesperson s
LEFT JOIN Orders o
ON o.sales_id = s.sales_id
LEFT JOIN company c
ON o.com_id = c.com_id
WHERE c.name='RED'
)