def numIdenticalPairs(nums) :
    nums=sorted(nums)
    count=0
    for i in range(len(nums)-1):
        
        for j in range(i+1,len(nums)):
            if nums[i]==nums[j] and i!=j:
                count+=1
                print(i,j,nums[i],nums[j],count)
            
    print(count)

nums = [1,2,3,1,1,3]
print(numIdenticalPairs(nums))
nums=[1,1,1,1]
print(numIdenticalPairs(nums))
nums=[1,2,3]
print(numIdenticalPairs(nums))

