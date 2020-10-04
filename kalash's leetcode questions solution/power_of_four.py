def isPowerOfFour(n): 
    if (n == 0): 
        return False
    while (n != 1): 
            if (n % 4 != 0): 
                return False
            n = n // 4
            print(n)
              
    return True
  
# Driver code 
test_no = 64
if(isPowerOfFour(64)): 
    print(test_no, 'is a power of 4') 
else: 
    print(test_no, 'is not a power of 4') 
