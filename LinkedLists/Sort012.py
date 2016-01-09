# Given a linked list of 0s, 1s and 2s, sort it

inputList = [0, 2, 2, 1, 0, 0, 1, 1, 1, 0, 2, 2, 2, 1]
print(inputList)
countArray = [0, 0, 0]

for number in inputList:
    countArray[number] += 1

print(countArray)

k = 0
inputList.clear()
for i in countArray:
    for j in range(0, i):
        inputList.append(k)
    k += 1

print(inputList)
