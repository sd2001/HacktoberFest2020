import random

jackpot=random.randint(1,100)

guess=int(input('guess the number'))

counter=1

while guess != jackpot:
    if guess > jackpot:
        print("inncorrect guess lower")
    else:
        print("Inncorrect guess higher")
    guess=int(input('guess the number'))
    counter = counter+1
print('correct')
print('you took',counter,'attempts')
