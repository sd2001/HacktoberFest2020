def detect(word):
    if word.isupper():
        return True
    elif word.islower():
        return True
    elif word[0].isupper() and word[1:].islower():
        return True
    else:
        return False

print(detect('USA'))
print(detect('FlaG'))
print(detect('leetcode'))
print(detect('Google'))
