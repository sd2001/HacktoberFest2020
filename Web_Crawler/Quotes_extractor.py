from bs4 import BeautifulSoup
import requests

search=input("Enter search terms here  ")
par={"q":search}
r=requests.get("https://www.brainyquote.com/search_results?",params=par)

soup=BeautifulSoup(r.text,"html.parser")
results=soup.findAll("div",{"class":"qll-bg"})

filename=search+'_Quotes.csv'
f=open(filename,"w")
headers="Author,Quote,Related_Topics\n"
f.write(headers)
i=1
for result in results:
    quote=result.find("a",{"title":"view quote"})
    author=result.find("a",{"title":"view author"})
    related_topics=result.findAll("a",{"class":"qkw-btn btn btn-xs oncl_list_kc"})
    print(i,'.' ,quote.text)
    print("Author: ",author.text)
    print("Related topics: ",end='')
    
    l=len(related_topics)
    j=1
    r=''
    for rt in related_topics:
        if j!=l:
            print(rt.text,end=',')
            r=r+';'+rt.text
        else:
            print(rt.text)
            r=r+','+rt.text
        j=j+1
    print('\n')
    f.write(author.text.replace(","," ")+','+quote.text.replace(","," ")+','+r.replace(","," ")+'\n')
    i=i+1
f.close()
