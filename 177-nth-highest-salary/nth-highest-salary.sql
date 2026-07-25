CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare M int;
set M = N-1;
  RETURN (
      # Write your MySQL query statement below.
      Select distinct salary
      from Employee
      order BY salary desc
      limit 1 OFFSET M

  );
END