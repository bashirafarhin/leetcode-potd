# Write your MySQL query statement below

-- SELECT Department, Employee, Salary
-- FROM (
--     SELECT e.name as Employee, e.salary as Salary, e.departmentId as id, d.name as Department,
--     MAX(e.salary) OVER( PARTITION BY e.departmentId ) as maxSalary
--     FROM Employee e
--     JOIN Department d
--     ON e.departmentId = d.id
-- ) t
-- WHERE Salary = maxSalary;

SELECT e.name as Employee, e.salary as Salary, d.name as Department
FROM Employee e
JOIN Department d
ON e.departmentId = d.id
WHERE e.salary = ( SELECT MAX(salary) FROM Employee WHERE departmentId = e.departmentId );