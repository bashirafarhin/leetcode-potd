# Write your MySQL query statement below
-- SELECT d.name as Department, e.name as Employee, MAX(e.salary) as Salary
-- FROM Employee e
-- JOIN Department d
-- ON e.departmentId = d.id
-- GROUP BY d.id;

SELECT Department, Employee, Salary
FROM (
    SELECT e.name as Employee, e.salary as Salary, e.departmentId as id, d.name as Department,
    MAX(e.salary) OVER( PARTITION BY e.departmentId ) as maxSalary
    FROM Employee e
    JOIN Department d
    ON e.departmentId = d.id
) t
WHERE Salary = maxSalary;