-- 1155 ms
SELECT
    Department.Name AS 'Department',
    a.Name AS 'Employee',
    a.Salary AS 'Salary'
FROM
    Employee AS a, Department
WHERE
    a.DepartmentId = Department.Id
    AND 3 > (
        SELECT COUNT(DISTINCT b.Salary)
            FROM
                Employee AS b
            WHERE
                a.Salary < b.Salary
                    AND a.DepartmentId = b.DepartmentId
        )
ORDER BY Department.Name, Salary DESC;

-- 官方题解 1446 ms
SELECT
    d.Name AS 'Department',
    a.Name AS 'Employee',
    a.Salary
FROM
    Employee a
    JOIN Department b ON a.DepartmentId = b.Id
WHERE
    3 > (SELECT
            COUNT(DISTINCT c.Salary)
        FROM
            Employee c
        WHERE
            c.Salary > a.Salary
                AND a.DepartmentId = c.DepartmentId
        )
