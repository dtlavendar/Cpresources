c = [[0 for j in range(51)] for i in range(51)]

for i in range(51):
    c[i][0] = c[i][i] = 1

for i in range(2, 51):
    for j in range(i, 0, -1):
        c[i][j] = c[i-1][j] + c[i-1][j-1]

# C(i, j) -> choose(i, j)
d = [1]
for i in range(1, 51):
    d.append(d[-1] * i + (-1 if i % 2 else 1));

n = int(input())
ans = 0
for i in range(n // 2 + n % 2, n + 1):
    ans += c[n][i] * d[n - i]


a = 1
for i in range(2, n + 1):
   a *= i
print(ans)
print(a)
print(ans / a)

