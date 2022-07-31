collatz_numbers = open("numbers.txt", "w")

mx = 1


for i in range(1, 3001):
    while i > 1:
        mx = max(mx, i)
        if i % 2 == 1:
            i = 3 * i + 1
        else:
            i = i // 2
    collatz_numbers.write(str(mx) + "\n")
    mx = 1

collatz_numbers.close()


