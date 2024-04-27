select A.id, coalesce(B.count, 0) as child_count
from ecoli_data as A
    left join
    (select parent_id, count(*) as count
     from ecoli_data
     group by parent_id     
     having parent_id is not null
    ) as B
    on A.id = B.parent_id

    

# group by parent_id
# 대장균개채와 자식수
# parentID group by