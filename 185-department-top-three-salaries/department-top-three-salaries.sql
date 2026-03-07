# Write your MySQL query statement below

SELECT d.name AS Department, e.name as Employee, e.salary as Salary
FROM (
    SELECT name, salary, departmentId,
    DENSE_RANK() OVER ( PARTITION BY departmentId ORDER BY salary DESC ) AS rk
    FROM Employee
) e
JOIN Department d
ON e.departmentId = d.id
WHERE rk BETWEEN 1 AND 3;