import smtplib
import ssl
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

sender_email = '' # enter the Gmail id of sender 
reciever_email = '' # enter reciever's email id
password = input('Enter passsword: ')

message = MIMEMultipart('alternative')
message['Subject'] = 'Multipart Test'
message['From'] = sender_email
message['To'] = reciever_email

# function to read html from external


def get_content(path):
    with open(path) as f:
        raw_lines = f.readlines()
    content = ''''''.join(raw_lines)
    return content


# Create the plain-text and HTML version of your message
text = '''\
  Hi,
  How are you?
  -CJ'''
html = get_content('index.html')

# Turn these into plain/HTML MIMEText objects
part1 = MIMEText(text, 'plain')
part2 = MIMEText(html, 'html')

# Add HTML/plain-text parts to MIMEMultipart message
# The email client will try yo render the last part first
message.attach(part1)
message.attach(part2)

# Create secure connection with server and send email
context = ssl.create_default_context()
with smtplib.SMTP_SSL('smtp.gmail.com', 465, context=context) as server:
    server.login(sender_email, password)
    server.sendmail(sender_email, reciever_email, message.as_string())
