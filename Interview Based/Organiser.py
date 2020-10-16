""" # -*- coding: utf-8 -*-
"""
Created on Tue Jul  7 17:23:27 2020

@author: RDX
"""
from datetime import datetime
#import time

print(datetime.now().strftime('%Y-%m-%d %H:%M'))


print(" WELCOME TO ORGANIZER " )
msg,times = input("Enter the message and time \n").split() 




while(datetime.now().strftime('%H:%M')!='times'):
    print("waiting")

print(msg)
 
    

 """