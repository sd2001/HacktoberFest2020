if __name__ == "__main__":
    
    s = input()
    new_s = ""
    for i in range(len(s)-1, -1, -1):
        new_s += s[i]
    print(new_s)


    if s == new_s: print("haha got ya !") 
    else:  print("NOpe")
        
    
       