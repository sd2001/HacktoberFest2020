import datetime
import win32com.client 
import os 

def timeStamped(fname, fmt='%Y-%m-%d-{fname}'):
        # This creates a timestamped filename so we don't overwrite our good work
        return datetime.datetime.now().strftime(fmt).format(fname=fname)

outlook=win32com.client.Dispatch("Outlook.Application").GetNameSpace("MAPI") 
'''
try:
    outlook = win32com.client.GetActiveObject('Outlook.Application')
except:
    outlook = win32com.client.Dispatch('Outlook.Application')
'''
inbox=outlook.GetDefaultFolder(6) #Inbox default index value is 6 
message=inbox.Items 
message2=message.GetLast() 
#subject=message2.Subject 
#body=message2.body 
date=message2.senton.date()    
#sender=message2.Sender 
attachments=message2.Attachments 
print(attachments.count) 
print(date)  

messages = inbox.Items
message = messages.GetFirst()

while True:

    try:
        
        attachments = message2.Attachments
        attachment = attachments.Item(1)
        fname = timeStamped(attachment)
        attachment.SaveASFile(os.getcwd() + '\\' + str(fname)) #Saves to the attachment to current folder
        print("Attachment downloaded")
        print (fname)  
        message2 = messages.GetNext()
    except:
        break
