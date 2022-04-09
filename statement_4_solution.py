n = int(input())
dp = [[0 for i in range(361)] for j in range(n + 1)]
mod = 1000000007
dp[0][0] = 1
for i in range(0, n):
    for j in range(0, 361):
        for k in range(1, 361):
            if j + k <= 360:
                assert(j + k <= 360)
                assert(j <= 360)
                assert(i + 1 <= n)
                dp[i + 1][j + k] += dp[i][j]
                dp[i + 1][j + k] %= mod

print(dp[n][360])

