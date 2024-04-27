select 
    A.item_id, A.item_name, A.rarity
from 
    item_info as A
    join item_tree as B 
        on A.item_id = B.item_id
where 
    A.item_id not in (select parent_item_id
                      from item_tree
                      where parent_item_id is not null
                     )
order by 
    A.item_id desc

# item_id가 parent_item_id에 없는애들만 출력