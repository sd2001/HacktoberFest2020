def shuffle(nums,n):
    a=[]
    for i in range(n):
        a.append(nums[i])
        a.append(nums[i+n])
    return(a)    



nums = [2,5,1,3,4,7]
n = 3
print(shuffle(nums,n))

nums = [1,2,3,4,4,3,2,1]
n = 4
print(shuffle(nums,n))

nums = [1,1,2,2]
n = 2
print(shuffle(nums,n))
