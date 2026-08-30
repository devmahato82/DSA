# Write your MySQL query statement below
SELECT max(salary) as SecondHighestSalary
FROM Employee
where salary < (
    SELECT max(salary)
    FROM Employee
)