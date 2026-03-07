# Write your MySQL query statement below
-- SELECT c.name as Customers
-- FROM Customers c
-- JOIN Orders o
-- WHERE c.id

SELECT name as Customers
FROM Customers c
WHERE NOT EXISTS ( SELECT 1 FROM Orders o WHERE c.id = o.customerId);