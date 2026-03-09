# Write your MySQL query statement below

SELECT id
FROM (
SELECT id, recordDate, temperature, 
LAG(temperature) OVER(ORDER BY recordDate) as prevTemp,
LAG(recordDate) OVER(ORDER BY recordDate) as prevDate
 FROM Weather
) t
WHERE prevTemp<temperature and 
DATEDIFF(recordDate, prevDate)=1;