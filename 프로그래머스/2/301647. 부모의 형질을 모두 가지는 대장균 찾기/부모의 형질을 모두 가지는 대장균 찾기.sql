select A.id, A.genotype, B.genotype parent_genotype
from ecoli_data as A 
join ecoli_data as B
on A.parent_id = B.id
where A.genotype & B.genotype = B.genotype
order by A.id

# 부모의 형질 모두 보유한
# id, genotype, parent_genotype
