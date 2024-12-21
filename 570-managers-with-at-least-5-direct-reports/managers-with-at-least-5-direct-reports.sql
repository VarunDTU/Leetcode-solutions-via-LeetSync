select e1.name from employee e1 where e1.id in( SELECT e2.managerId 
    FROM employee e2
    GROUP BY e2.managerID
    HAVING COUNT(e2.id) >= 5)