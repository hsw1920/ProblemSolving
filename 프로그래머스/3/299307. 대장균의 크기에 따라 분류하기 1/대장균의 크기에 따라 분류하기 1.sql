select id, 
    CASE 
        WHEN size_of_colony <= 100 THEN 'LOW'
        when size_of_colony <= 1000 then "MEDIUM"
        ELSE 'HIGH'
    END AS size
from ecoli_data
order by id