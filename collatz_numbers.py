collatz_numbers = open("numbers.txt", "w")
def collatz(num):
    collatz_numbers.write(str(num) + " ")
    if num == 1:
        return
    elif num % 2 == 0:
        collatz(num // 2)
    else:
        collatz(num * 3 + 1)
    
for i in range(1, 3001):
    collatz(i)
    collatz_numbers.write("\n")


