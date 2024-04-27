select cart_id
from (
select cart_id, name
from cart_products as A
where name = "Yogurt"
union
select cart_id, name
from cart_products as A
where name = "Milk"
) as B
group by cart_id
having count(cart_id) >= 2


# 우유, 요거트 동시구입한 장바구니?