# Write your MySQL query statement below
-- SELECT t.request_at, COUNT(u1.users_id) as a
-- FROM Trips t
-- LEFT JOIN Users u1
-- ON t.client_id = u1.users_id
-- LEFT JOIN Users u2
-- ON t.driver_id = u2.users_id
-- AND u.banned = 'No'
-- AND u2.banned = 'No'
-- AND (t.status = 'cancelled_by_driver' OR t.status = 'cancelled_by_client')
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- GROUP BY t.request_at;

-- SELECT t.request_at, COUNT(u.users_id) as b
-- FROM Trips t
-- LEFT JOIN Users u
-- ON t.client_id = u.users_id
-- AND u.banned = 'No'
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- GROUP BY t.request_at;

-- SELECT t1.request_at AS Day, ROUND(t1.a/t2.b,2) AS `Cancellation Rate`
-- FROM (
-- SELECT t.request_at as request_at, COUNT(u.users_id) as a
-- FROM Trips t
-- LEFT JOIN Users u
-- ON t.client_id = u.users_id
-- AND (t.status = 'cancelled_by_driver' OR t.status = 'cancelled_by_client')
-- AND u.banned = 'No'
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- GROUP BY t.request_at
-- ) t1
-- JOIN (
-- SELECT t.request_at as request_at, COUNT(u.users_id) as b
-- FROM Trips t
-- LEFT JOIN Users u
-- ON t.client_id = u.users_id
-- AND u.banned = 'No'
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- GROUP BY t.request_at
-- SELECT t1.request_at AS Day, ROUND(t1.a/t2.b,2) AS `Cancellation Rate`
-- FROM (
-- …SELECT t.request_at as request_at, COUNT(u.users_id) as b
-- FROM Trips t
-- LEFT JOIN Users u
-- ON t.client_id = u.users_id
-- AND u.banned = 'No'
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
-- GROUP BY t.request_at
-- ) t2
-- ON t1.request_at = t2.request_at;
-- ) t2
-- ON t1.request_at = t2.request_at;

SELECT
t.request_at AS "Day",
ROUND(
    SUM(CASE WHEN t.status = 'cancelled_by_driver' OR t.status = 'cancelled_by_client' THEN 1 ELSE 0 END)*1.0/COUNT(*),2) AS "Cancellation Rate"
FROM Trips t
JOIN Users c
ON t.client_id = c.users_id
JOIN Users d
ON t.driver_id = d.users_id
WHERE c.banned = 'No'
AND d.banned = 'No'
AND t.request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY t.request_at;