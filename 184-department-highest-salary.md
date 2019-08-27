# 184. 部门工资最高的员工

`Employee` 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id。

```text
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Henry | 80000  | 2            |
| 3  | Sam   | 60000  | 2            |
| 4  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
```

`Department` 表包含公司所有部门的信息。

```text
+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
```

编写一个 SQL 查询，找出每个部门工资最高的员工。例如，根据上述给定的表格，Max 在 IT 部门有最高工资，Henry 在 Sales 部门有最高工资。

```text
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
```

## 解法

1. GROUP BY
   先对 DepartmentId 字段分组查询最大值，得到不同 DepartmentId 下的最大值

   ```sql
   SELECT DepartmentId, max( Salary )
   FROM Employee
   GROUP BY DepartmentId
   ```

2. 再进行条件查询（WHERE、JOIN、IN），请查看 [SQL文件](./184-department-highest-salary.sql)，时间只是单次执行的时间，不是统计值。
