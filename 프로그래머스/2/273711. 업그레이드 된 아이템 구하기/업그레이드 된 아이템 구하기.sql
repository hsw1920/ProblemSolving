select W.ITEM_ID, W.ITEM_NAME, W.RARITY
from item_info as Q
join 
(
select A.item_id as ITEM_ID, A.item_name as ITEM_NAME, A.rarity as RARITY, B.parent_item_id
from item_info as A
join item_tree as B
on A.item_id = B.item_id
) as W
on Q.item_id = W.parent_item_id
where Q.rarity = "RARE"
order by ITEM_ID desc


# parent_item_id가 null이 아닌애들