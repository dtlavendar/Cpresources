#include <stdio.h>
long long dp[501][361], i, j, k;
const int m = 1000000007;
main() {
	int n;
	scanf("%d", &n);
	dp[0][0] = 1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 360; j++) {
			for (k = 1; k <= 360; k++) {
				if(j + k > 360)
					break;
				dp[i + 1][j + k] = (dp[i + 1][j + k] + dp[i][j]);
			}
		}
	}
	printf("%d\n", dp[n][360]);
}
