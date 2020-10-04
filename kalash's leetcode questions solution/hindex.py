class Solution:
    def hIndex(citations):
        if len(citations) == 0:
            return 0
        
        res = 0
        citations.sort(reverse = True)

        if citations[-1] >= len(citations):
            return len(citations)
        
        for i in range(1, len(citations)+1):
            if i > citations[i-1]:
                res = i-1
                break
        return res
print(Solution.hIndex([1,3,0,5,6])) #output = 3
print(Solution.hIndex([0]))         #output = 0
print(Solution.hIndex([1,1]))       #output = 1 
print(Solution.hIndex([0,0,]))      #output = 0
