def kids(can,extra):
    maxi=max(can)
    out = [x+extra>=maxi for x in can]
    return(out)




candies = [2,3,5,1,3]
extraCandies = 3
print(kids(candies,extraCandies))

candies = [4,2,1,1,2]
extraCandies = 1
print(kids(candies,extraCandies))
