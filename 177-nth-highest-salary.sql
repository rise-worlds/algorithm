CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      DECLARE P INT;
      SET P = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT(
        SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT P,1
      )
  );
END


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
      DECLARE P INT;
      SET P = N-1;
  RETURN (
      # Write your MySQL query statement below.
      SELECT
        IFNULL(
            (
                SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT P,1
            ),
            NULL)
  );
END