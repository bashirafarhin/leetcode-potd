-- # Write your MySQL query statement below
-- SELECT
--  ROUND(
--     (
--         SELECT COUNT(DISTINCT a1.player_id)
--     FROM Activity a1
--     WHERE EXISTS(
--         SELECT 1 FROM Activity a2 WHERE a1.player_id=a2.player_id AND a2.event_date = DATE_ADD(a1.event_date, INTERVAL 1 DAY)
--     )
--     )

--      / (SELECT COUNT(DISTINCT player_id) FROM Activity)
--      , 2
--  ) as fraction;
-- SELECT player_id, MIN(event_date) as first_login
-- FROM Activity
-- GROUP BY player_id

-- compare above table with original

-- never use normal arithmetic in dates use date functions
SELECT ROUND( dst_player/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
FROM (

SELECT COUNT(a.player_id) AS dst_player
FROM (
    SELECT player_id, MIN(event_date) as first_login
    FROM Activity
    GROUP BY player_id
) t
JOIN Activity a
ON t.player_id=a.player_id AND DATEDIFF(a.event_date, t.first_login)=1
) b