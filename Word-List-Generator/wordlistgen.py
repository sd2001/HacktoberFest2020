print("Welcome to WordListGenerator!\n")

try:
    choice = int(input("1. Append\n2. Prepend\nEnter Your Choice: "))
    if choice not in [1, 2]:
        print("Invalid Choice! Exiting......")
        exit(0)
    
    keyword = input("Enter The Keyword: ")
    start = int(input("Enter The Start Number: "))
    end = int(input("Enter The End Number: "))
 
    if choice == 1:
        f = open(f'{keyword}.txt', 'a')
        for i in range(start, end+1):
            f.write(f"{keyword}{str(i)}\n")
        f.close()
        print(f'{keyword}.txt Created!')
    
    else:
        f = open(f'{keyword}.txt', 'a')
        for i in range(start, end+1):
            f.write(f"{str(i)}{keyword}\n")
        f.close()
        print(f'{keyword}.txt Created!')

except:
    print("Invalid Input! Exiting.....")