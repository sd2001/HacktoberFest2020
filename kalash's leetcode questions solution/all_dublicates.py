import collections
def s(nums):
        
    d = collections.Counter(nums)
    out = []
      
    for key in d:
        
        if d[key]>=2:
            out=out+[key]
    out=sorted(out)
    print(out)

    return out
s([4,3,2,7,8,2,3,1])
