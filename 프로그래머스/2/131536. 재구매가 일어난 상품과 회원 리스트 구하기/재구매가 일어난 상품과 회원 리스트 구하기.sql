-- 코드를 입력하세요

# 동일한 회원 동일상품 재구매
# select 재구매한 회원ID, 상품ID 출력
## order by 회원ID asc
## 회원ID같으면 상품ID기준으로 desc

SELECT user_id, product_id
from online_sale
group by 1,2
having count(product_id) > 1
order by user_id asc, product_id desc

