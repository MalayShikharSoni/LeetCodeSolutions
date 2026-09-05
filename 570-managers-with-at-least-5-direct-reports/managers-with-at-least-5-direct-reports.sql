# Write your MySQL query statement below
SELECT e.name AS name
FROM Employee e JOIN Employee m
ON e.id = m.managerId
GROUP BY e.id
HAVING COUNT(m.managerId) >= 5;