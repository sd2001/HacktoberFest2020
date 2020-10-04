import collections
def s(nums):
        
    d = collections.Counter(nums)
        
    out = []
        
    for i in nums:
            
        count = 0
            
        for key in d:
            if key < i:
                count += d[key]
            
        out = out + [count]

    return out
s([10,20,130,18,10,10])
