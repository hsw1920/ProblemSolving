with t1 as (select A.book_id as aa, A.author_id as a, B.author_name as b, A.category as c, A.price as d
    from book as A
    join author as B
    on A.author_id = B.author_id
)

select B.author_id, author_name, category, sum(sales * price)
from book_sales as Q
    join book as B on B.book_id = Q.book_id
    join author as W on B.author_id = W.author_id
    where  year(Q.sales_date) = 2022 and month(Q.sales_date) = 1
    group by category, author_id
    order by author_id, category desc
    

# select t1.a author_id, t1.b author_name, t1.c category, (t1.d * C.sales) as total_sales
# from t1
#     join book_sales as C
#     on t1.aa = C.book_id and year(C.sales_date) = 2022 and month(C.sales_date) = 1
#     group by C.book_id
# order by author_id, category desc
    