select A.id, A.name, A.host_id
from places as A
join
(select host_id
from places
group by host_id
having count(*) >= 2
) as B
on A.host_id = B. host_id
order by A.id