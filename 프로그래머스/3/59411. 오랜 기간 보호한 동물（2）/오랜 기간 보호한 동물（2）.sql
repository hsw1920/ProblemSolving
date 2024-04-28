select B.animal_id, B.name
from animal_ins as A
    join animal_outs as B
    on A.animal_id = B.animal_id
order by B.datetime-A.datetime desc
limit 2
# 입양간 동물, 보호기간 가장긴 동물 두마리