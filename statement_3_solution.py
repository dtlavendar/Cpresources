n, m = list(map(int, input().split()))

firstStrings = input().split()
secondStrings = input().split()

for i in range(m):
    for j in range(n):
        if secondStrings[i] == firstStrings[j]:
            firstStrings[j]=""


for i in range(n):
    if firstStrings[i] == "":
        continue
    print(firstStrings[i],end=" ")
