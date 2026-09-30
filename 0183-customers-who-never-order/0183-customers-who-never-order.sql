# Write your MySQL query statement below
select c.name as customers
from Customers c
left join orders o
on c.id = o.customerID
where o.customerID is null;