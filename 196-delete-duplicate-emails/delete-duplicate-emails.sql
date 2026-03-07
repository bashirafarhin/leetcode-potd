# Write your MySQL query statement below
-- DELETE FROM (
--     SELECT id, email,
--     RANK() OVER ( PARTITION BY email ORDER BY id ) as "rank"
--     FROM Person
-- ) t
-- WHERE "rank" > 1;

-- DELETE FROM Person
-- WHERE id IN (
--     SELECT id
--     FROM (
--         SELECT id,
--     ROW_NUMBER() OVER ( PARTITION BY email ORDER BY id ) as "rank"
--     FROM Person
--     WHERE "rank" > 1
--     ) t
-- );

DELETE FROM Person
WHERE id IN (
    SELECT id
    FROM (
        SELECT id,
    ROW_NUMBER() OVER ( PARTITION BY email ORDER BY id ) as r
    FROM Person
    ) t
    WHERE r > 1
);