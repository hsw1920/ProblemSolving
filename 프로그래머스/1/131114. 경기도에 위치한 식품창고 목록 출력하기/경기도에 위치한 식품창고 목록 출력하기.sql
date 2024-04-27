select warehouse_id, warehouse_name, address, coalesce(freezer_yn,"N")
from food_warehouse
where substr(warehouse_name,4,2) = '경기'
order by warehouse_id asc