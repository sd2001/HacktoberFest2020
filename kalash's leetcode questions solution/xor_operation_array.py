from operator import ixor
from functools import reduce
def xop(n=4,start=3):
    nums=[]
    for i in range(0,n):
        nums.append(start+2*i)
    return (reduce(ixor,nums))
   

print(xop())
