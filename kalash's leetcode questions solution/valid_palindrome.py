def isp(s):
    s=''.join(e.lower() for e in s if e.isalnum())
    print(s)
    if s==s[::-1]:
        return True
    else:
        return False

print(isp("A man, a plan, a canal: Panama"))
