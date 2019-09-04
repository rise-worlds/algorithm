SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
;

SELECT b.Salary AS SecondHighestSalary 
    FROM ( SELECT 1 AS temp FROM Employee limit 1 ) a 
    LEFT JOIN ( SELECT Salary FROM Employee GROUP BY Salary ORDER BY Salary DESC LIMIT 1, 1 ) b ON 1=1
;