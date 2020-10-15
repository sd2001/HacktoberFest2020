""" Add top four numbers if size > 4 else return the sum of the whole array
 """


def max(arr, lst):
    c = 0
    for nums in range(0, len(arr)):
        if arr[nums] > c and arr[nums] not in lst:
            c = arr[nums]
    return c

def top_four(arr):
    
    if(len(arr) <= 4):
        sum = 0
        for nums in range(0, len(arr)):
            sum += arr[nums]
        return sum
    else:
        sum = 0
        lst = []
        for i in range(0, 4):
            m = max(arr, lst)
            lst.append(m)
            sum += m
        
        return sum
    

if __name__ == "__main__":
    print(top_four([4, 5, 9, -1, 8, 8, 5, 4]))
    