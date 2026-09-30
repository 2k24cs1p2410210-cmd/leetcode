# Write your MySQL query statement below
select user_id ,
concat(
    upper(left(lower(name),1)),
    substring(lower(name),2)
) AS name
from users 
order by user_id;
