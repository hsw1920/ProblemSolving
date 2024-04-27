select count(genotype) count
from ecoli_data
where (genotype & 1 or genotype & 4) and !(genotype & 2)

## 2번형질X , 1,3형질 OK