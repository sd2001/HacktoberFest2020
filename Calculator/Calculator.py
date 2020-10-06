# -*- coding: utf-8 -*-

print("Calculator: ")
while (True):
  print("")
  print("-------------------------------------")
  print("\nPress 1 for Addition: ")
  print("Press 2 for Subtraction: ")
  print("Press 3 for Multiplication: ")
  print("Press 4 for Division: ")
  print("Press 5 to Quit: ")
  
  print("") 
  
  a = int(input("Enter Your Choice: "))

  if (a==1):
      print("\n---Addition---\n")
      try:
          x = int(input("Enter 1st Number: "))
          y = int(input("Enter 2nd Number: "))
          print("\nAddition Result of {} and {} = {}".format(x,y,x+y))
      except ValueError:
          print("Please enter integers.")
  elif (a==2):
      print("\n---Subtraction---\n")
      try:
          x = int(input("Enter 1st Number: "))
          y = int(input("Enter 2nd Number: "))
          print("\nSubtraction Result of {} and {} = {}".format(x,y,x-y)) 
      except ValueError:
          print("Please enter integers.")
    
  elif (a==3):
      print("\n---Multiplication---\n")
      try:
          x = int(input("Enter 1st Number: "))
          y = int(input("Enter 2nd Number: "))
          print("\nMultiplication Result of {} and {} = {}".format(x,y,x*y))  
      except ValueError:
          print("Please enter integers.")
    
  elif (a==4):
      print("\n---Division---\n")
      try:
        x = int(input("Enter 1st Number: "))
        y = int(input("Enter 2nd Number: "))
        c = x/y
        print("\nDivision Result of {} and {} = {}".format(x,y,c))
      except ZeroDivisionError:
        print("\nDivision by 0 is not accepted.")
      except ValueError:
        print("Please enter integers.")

  elif (a==5):
    print("\nThankyou for using the Calculator.")
    print("-------------------------------------")
    break
  else:
    print("\nPlease enter a number from 1-5.")
    
    
