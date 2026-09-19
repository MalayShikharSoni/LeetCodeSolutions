# Write your MySQL query statement below
WITH cte as (
    SELECT num,
    LEAD(num, 1) OVER() AS num1,
    LEAD(num, 2) OVER() AS num2
    FROM Logs
)

SELECT DISTINCT num AS ConsecutiveNums FROM cte where num = num1 AND num = num2;