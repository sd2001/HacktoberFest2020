

def longestUniqueSubsttr(string):
    dic = {} 
    max_len = 0
    start = 0	
    for end in range(len(string)):
        if string[end] in dic:
            start = max(start, dic[string[end]] + 1)
            
        dic[string[end]] = end
        max_len = max(max_len, end-start + 1)
    return max_len



