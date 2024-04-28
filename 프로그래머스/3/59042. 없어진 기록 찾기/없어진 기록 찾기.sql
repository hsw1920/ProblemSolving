select A.animal_id, A.name
from animal_outs as A
join
    (
    select outs.animal_id, ins.name
    from animal_outs as outs
    left join animal_ins as ins
    on outs.animal_id = ins.animal_id
    where outs.name is not null
    ) as B
on A.animal_id = B.animal_id and B.name is null
order by animal_id
    
    
# select * from animal_outs
