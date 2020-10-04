import os
import time
import datetime as dt
import win32com.client

def get_time():
    # this is set to the current time
    date_time = dt.datetime.now()
    # this is set to one day ago
    lastDayDateTime = dt.datetime.now() - dt.timedelta(days = 1)
    #This is set to one minute ago; you can change timedelta's argument to whatever you want it to be
    outlook = win32com.client.Dispatch("Outlook.Application").GetNameSpace("MAPI")
    inbox = outlook.GetDefaultFolder(6)

    # retrieve all emails in the inbox, then sort them from most recently received to oldest (False will give you the reverse). 
    # Not strictly necessary, but good to know if order matters for your search
    messages = inbox.Items
    
    messages.Sort("[ReceivedTime]", True)

    # restrict to messages from the past hour based on ReceivedTime using the dates defined above.
    # lastHourMessages will contain only emails with a ReceivedTime later than an hour ago
    # The way the datetime is formatted DOES matter; You can't add seconds here.
    lastDayMessages = messages.Restrict("[ReceivedTime] >= '" +lastDayDateTime.strftime('%m/%d/%Y %H:%M %p')+"'")
 
    print ("\nCurrent time: "+date_time.strftime('%m/%d/%Y %H:%M %p')+'\n')
    print ("Messages from the past day: \n")
    '''
    for message in lastDayMessages:
        print (message.subject)
        print (message.ReceivedTime)
        message = lastDayMessages.GetNext()
    '''
    # GetFirst/GetNext will also work, since the restricted message list is just a shortened version of your full inbox.
    
    #print ("\nUsing GetFirst/GetNext")
    message = lastDayMessages.GetFirst()
    
    while message:
        print (message.subject)
        print (message.ReceivedTime)
        attachments = message.Attachments
        attachment = attachments.Item(1)
        fname = timeStamped(attachment)
        attachment.SaveASFile(os.getcwd() + '\\' + str(fname)) #Saves to the attachment to current folder
        message = lastDayMessages.GetNext()
        print("Attachment downloaded")
        print (fname+'\n')
        
        

def timeStamped(fname, fmt='%Y-%m-%d-{fname}'):
        import datetime
        # This creates a timestamped filename so we don't overwrite our good work
        return datetime.datetime.now().strftime(fmt).format(fname=fname)

if __name__ == '__main__' :
    get_time()