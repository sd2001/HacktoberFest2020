def d(nums):
                
    l = []
    for i in range(0,len(nums),2):
        while nums[i] != 0:

            l.append(nums[i+1])

            nums[i] -= 1
                
    return l
print(d([1,1,2,3]))
