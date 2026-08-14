# Write your MySQL query statement below
select r.contest_id, Round((count(u.user_id)/(select count(*) from users))*100,2) as percentage
from Users u
right Join register r
on u.user_id = r.user_id
group by r.contest_id
order by percentage desc, r.contest_id asc

