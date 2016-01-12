upperLimit = 1000
primeList = []
for i in range(2, upperLimit):
    primeList.append(i)

for i in primeList:
    if i != "x":
        j = primeList.index(i) + i
        while j < (upperLimit - 2):
            primeList[j] = "x"
            j += i

for i in primeList:
    if i != "x":
        print(i, end=", ")
