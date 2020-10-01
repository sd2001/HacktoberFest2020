import win32com.client
import os
import time
import datetime as dt

# this is set to the current time
date_time = dt.datetime.now()
# this is set to one hour ago
lastHourDateTime = dt.datetime.now() - dt.timedelta(hours = 1)
#This is set to one minute ago; you can change timedelta's argument to whatever you want it to be
lastMinuteDateTime = dt.datetime.now() - dt.timedelta(minutes = 1)

outlook = win32com.client.Dispatch("Outlook.Application").GetNameSpace("MAPI")
inbox = outlook.GetDefaultFolder(6)

# retrieve all emails in the inbox, then sort them from most recently received to oldest (False will give you the reverse). Not strictly necessary, but good to know if order matters for your search
messages = inbox.Items
messages.Sort("[ReceivedTime]", True)

# restrict to messages from the past hour based on ReceivedTime using the dates defined above.
# lastHourMessages will contain only emails with a ReceivedTime later than an hour ago
# The way the datetime is formatted DOES matter; You can't add seconds here.
lastHourMessages = messages.Restrict("[ReceivedTime] >= '" +lastHourDateTime.strftime('%m/%d/%Y %H:%M %p')+"'")

lastMinuteMessages = messages.Restrict("[ReceivedTime] >= '" +lastMinuteDateTime.strftime('%m/%d/%Y %H:%M %p')+"'")

print ("Current time: "+date_time.strftime('%m/%d/%Y %H:%M %p'))
print ("Messages from the past hour:")

for message in lastHourMessages:
    print (message.subject)
    print (message.ReceivedTime)

print ("Messages from the past minute:")

for message in lastMinuteMessages:
    print (message.subject)
    print (message.ReceivedTime)

# GetFirst/GetNext will also work, since the restricted message list is just a shortened version of your full inbox.
print ("Using GetFirst/GetNext")
message = lastHourMessages.GetFirst()
while message:
    print (message.subject)
    print (message.ReceivedTime)
    message = lastHourMessages.GetNext()