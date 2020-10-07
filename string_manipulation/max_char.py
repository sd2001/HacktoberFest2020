str=input("String:")
c=str.split()
k=set({})
m=c[0]
for i in c:
    if (c.count(m)<c.count(i)):
        m=i
    if(c.count(m)==c.count(i)):
        k.add(i)
print(k)
