count=0

num=8
while num>0:
    if num%2==0:
        num=num//2
        count+=1
    else:
        num=num-1
        count+=1

print(count)
