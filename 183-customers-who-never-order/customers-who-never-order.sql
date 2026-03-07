# Write your MySQL query statement below
-- SELECT c.name as Customers
-- FROM Customers c
-- JOIN Orders o
-- ON c.id = o.customerId
-- WHERE o.customerId is NULL;

SELECT c.name as Customers
FROM Customers c
LEFT JOIN Orders o
ON c.id = o.customerId
WHERE o.customerId IS NULL;

-- SELECT name as Customers
-- FROM Customers c
-- WHERE NOT EXISTS ( SELECT 1 FROM Orders o WHERE c.id = o.customerId );