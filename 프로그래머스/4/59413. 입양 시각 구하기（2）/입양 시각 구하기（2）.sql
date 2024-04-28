with recursive cte as (
    select 0 as hour
    union all
    select hour + 1 from cte
    where hour<23
)

select hour, count(A.datetime) count
from cte
    left outer join animal_outs as A
    on cte.hour = hour(A.datetime)
    group by hour
    order by hour

