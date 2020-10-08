import urllib.parse
import urllib.request
import sys

"""Feel Free to make changes to the code! Just follow the PEP-8 Guidelines"""

def shortUrl(url):
    requestUrl = 'http://tinyurl.com/api-create.php?' + urllib.parse.urlencode({'url':url})
    print(urllib.request.urlopen(requestUrl).read().decode('utf-8'))

if __name__ == "__main__":
    if(len(sys.argv) == 1):
        print("Please insert an URL")
    elif(len(sys.argv) == 2):
        shortUrl(sys.argv[1])
    elif(len(sys.argv) > 2):
        if(sys.argv[1] == "-m"):
            for i in range(2, len(sys.argv)):
                shortUrl(sys.argv[i])
        else:
            print("Please use the flag -m for multiple arguments")
