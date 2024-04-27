select * 
from
(
select B.user_id, B.nickname, sum(A.price) as total_sales
from used_goods_board as A
    join used_goods_user as B
    on A.writer_id = B.user_id and status = "DONE"
group by B.user_id
) as Q
where Q.total_sales >= 700000
order by total_sales



