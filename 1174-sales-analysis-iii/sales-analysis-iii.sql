# Write your MySQL query statement below


select
p.product_id,
p.product_name
from Product p
join Sales s
on p.product_id = s.product_id
group by p.product_id
HAVING SUM(
    CASE
        WHEN s.sale_date not BETWEEN '2019-01-01' AND '2019-03-31'
        THEN 1
        ELSE 0
    END
) = 0
;