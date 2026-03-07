# Write your MySQL query statement below

SELECT c.name as Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.id IS NULL;

-- SELECT name as Customers
-- FROM Customers c
-- WHERE NOT EXISTS ( SELECT 1 FROM Orders o WHERE c.id = o.customerId );

-- SELECT name as Customers
-- FROM Customers
-- WHERE id NOT IN ( SELECT CustomerId FROM Orders );