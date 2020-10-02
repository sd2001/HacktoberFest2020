from bs4 import BeautifulSoup
from urllib.request import urlopen
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
stop_words = set(stopwords.words('english'))
stop_words.add('...')
url = 'http://books.toscrape.com/catalogue/category/books/historical-fiction_4/index.html'
content = urlopen(url).read()
soup = BeautifulSoup(content)
results=soup.findAll("h3")
for result in results:
 word_tokens = result.text.split()
 filtered_sentence = []
 for w in word_tokens:
 if w not in stop_words:
 filtered_sentence.append(w)
 print(filtered_sentence)