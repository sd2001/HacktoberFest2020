def addr(addd):
    ad=list(addd)
    a=[]
    for i in range(len(ad)):
        if ad[i]=='.':
            a.append('[.]')
        else:
            a.append(ad[i])
            
            s=''.join(a)
    print("{}".format(s))


addd="1.1.1.1.1.1"
print(addr(addd))

addd="255.100.50.0"
print(addr(addd))
