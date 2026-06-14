# Write your MySQL query statement below
select
p.product_id,
round(
    case when u.product_id is null then 0 else sum(p.price * u.units)/sum(u.units) end
    ,2) as average_price
from Prices p
left join UnitsSold u
on p.product_id = u.product_id
where (u.product_id is null) or (p.start_date <= u.purchase_date and  u.purchase_date <= p.end_date)
group by p.product_id
;