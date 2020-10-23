import json
from difflib import get_close_matches

data = json.load(open("data.json"))

def translate(w):
    w = w.lower()
    if w in data:
        return data[w]
    elif w.title() in data:
        return data[w.title()]
    elif w.upper() in data:
        return data[w.upper()]
    elif len(get_close_matches(w, data.keys(), cutoff=0.8)) > 0:
        yn = input("Did you mean %s word? Enter Y if yes, N if no :" % get_close_matches(w, data.keys(), cutoff=0.8)[0])
        if yn == "Y" or yn == "y":
            return data[get_close_matches(w, data.keys(), cutoff = 0.8)[0]]
        elif yn == "N" or yn == "n":
            return "The word doesn't exist. please double check it"
        else:
            return "We didn't understand your query"
    else:
        return "The word doesn't exist. Please double check it."

word = input("Enter a word:")

output = translate(word)

if type(output) == list:
    for item in output:
        print(item)
elif type(output) == str:
    print(output)