-- 内连 950 ms
select d.Name as Department, e.Name as Employee, e.Salary from
    (select MAX(Salary) as Salary, DepartmentId from Employee group by DepartmentId) t 
    join Employee e on e.Salary = t.Salary and e.DepartmentId = t.DepartmentId
    join Department d on d.Id = e.DepartmentId

-- 官方题解 子查询 + 内连 570 ms
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
    JOIN Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId, Salary) IN
    (
        -- 部门内查询最高工资
        SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)

-- WHERE 内连 547 ms
SELECT
    c.Name AS Department,
    a.Name AS Employee,
    b.Max_Salary AS Salary
FROM 
    Employee AS a,
    (
        SELECT DISTINCT DepartmentId, MAX(Salary) AS Max_Salary
        FROM Employee
        GROUP BY DepartmentId
    ) AS b
    JOIN Department as c ON b.DepartmentId = c.Id
WHERE a.DepartmentId = b.DepartmentId
    AND a.Salary = b.Max_Salary

-- WHERE 522 ms
SELECT
    b.Name AS Department,
    a.Name AS Employee,
    c.Max_Salary AS Salary
FROM 
    Employee AS a,
    Department AS b,
    (
        SELECT DISTINCT DepartmentId, MAX(Salary) AS Max_Salary
        FROM Employee
        GROUP BY DepartmentId
    ) AS c
WHERE a.DepartmentId = c.DepartmentId
    AND a.DepartmentId = b.Id
    AND a.Salary = c.Max_Salary
