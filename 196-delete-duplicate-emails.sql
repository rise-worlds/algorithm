-- 官方题解，DELETE + 自连接
DELETE a FROM Person a,
    Person b
WHERE
    a.Email = b.Email -- 利用where进行自连接
    AND a.Id > b.Id -- 选择Id较大的行


-- DELETE + 子查询，实测效率更高
DELETE FROM Person
WHERE Id NOT IN (   -- 删除不在查询结果中的值
    SELECT id FROM
   (
       SELECT MIN(Id) AS Id -- 排除Email相同时中Id较大的行
       FROM Person
       GROUP BY Email
   ) AS temp    -- 此处需使用临时表，否则会发生报错
)
