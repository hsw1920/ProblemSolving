select A.item_id, A.item_name
from item_info as A
join item_tree as B
on A.item_id = B.item_id
where B.parent_item_id is null