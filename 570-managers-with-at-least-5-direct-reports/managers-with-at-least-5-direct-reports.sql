# Write your MySQL query statement below
-- id=manager_id
-- 
-- id, name, department, managerId
-- id, name, department, managerId

-- 2nd row id will be employees
-- group by managerId
-- having

SELECT e1.name
FROM Employee e1
JOIN Employee e2
ON e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e2.id)>=5;