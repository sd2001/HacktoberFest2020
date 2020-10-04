from collections import Counter
def l(s):
    if len(s)==1:
        return 1
    d=Counter(s)

    even=0
    odd=[]
    for i in d.values():
      
        if i%2==0:
            even+=i
        else:
            odd.append(i)
    if len(odd)>0:
        even=even+max(odd)
        odd.sort()
        odd.pop(-1)
        odd=[j-1 for j in odd]
    return even+sum(odd)
print(l("abccccdd"))
print(l('bb'))
