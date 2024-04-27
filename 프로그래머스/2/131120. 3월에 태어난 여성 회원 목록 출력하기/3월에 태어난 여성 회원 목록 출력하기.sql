SELECT member_id, member_name, gender, date_format(date_of_birth, "%Y-%m-%d") as date_of_birth
from member_profile as M
where 
M.tlno is not null 
and M.gender is not null 
and M.date_of_birth is not null 
and M.gender = 'W' and month(M.date_of_birth) = 3
order by member_id