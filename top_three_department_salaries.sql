# Write your MySQL query statement below
# top 3 department salaries
SELECT Department, Employee, Salary
FROM(
    SELECT
        e.name AS Employee,
        d.name as Department,
        e.salary as Salary,
        DENSE_RANK() OVER (PARTITION BY d.name ORDER BY Salary DESC) AS salary_rank
    FROM
        Employee e
    JOIN Department d ON e.departmentId = d.id
) AS rank_table 
WHERE salary_rank <= 3;
