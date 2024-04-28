select animal_id, name
from animal_ins as A
where A.name like "%el%"
    and A.animal_type = "dog"
order by name