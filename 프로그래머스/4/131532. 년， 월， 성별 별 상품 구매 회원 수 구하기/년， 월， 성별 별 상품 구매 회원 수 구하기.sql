select 
    year(B.sales_date) year, 
    month(B.sales_date) month, 
    A.gender gender, 
    count(distinct A.user_id) users
from user_info as A 
    join online_sale as B
    on A.user_id = B.user_id and A.gender is not null
group by year,month,gender
order by year,month,gender

# select sales_date from online_sale
