select 
    year(DIFFERENTIATION_DATE) as year
    , (B.size - A.size_of_colony) as year_dev
    , A.id
from 
    ECOLI_DATA as A,
    (select
        year(differentiation_date) as year
        , max(size_of_colony) as size
     from ecoli_data
     group by year
    ) as B
where
    year(A.differentiation_date) = B.year
order by
    year, year_dev