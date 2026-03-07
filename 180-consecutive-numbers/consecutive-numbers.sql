-- # Write your MySQL query statement below

-- with cte1 as (
-- SELECT num,
-- LAG(num) OVER( ORDER BY id ) as prev_num
-- FROM Logs
-- ), cte2 as (
-- SELECT num, prev_num,
-- (CASE prev_num WHEN num THEN 0 ELSE 1 END) as new_group
-- FROM cte1
-- ), cte3 as (
-- SELECT num,
-- SUM(new_group) OVER( ORDER BY prev_num ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW ) as group_id
-- FROM cte2
-- ) SELECT num as ConsecutiveNums
-- FROM cte3
-- WHERE group_id >=3;
# Write your MySQL query statement below

with cte1 as (
SELECT id, num,
LAG(num) OVER( ORDER BY id ) as prev_num
FROM Logs
), cte2 as (
SELECT id, num, prev_num,
(CASE prev_num WHEN num THEN 0 ELSE 1 END) as new_group
FROM cte1
), cte3 as (
SELECT num,
SUM(new_group) OVER( ORDER BY id ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW ) as group_id
FROM cte2
) SELECT DISTINCT num as ConsecutiveNums
FROM cte3
GROUP BY group_id
HAVING COUNT(*)>=3;