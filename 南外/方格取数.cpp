#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int i, j, n, m;
int a[110][110], f[110][110], x, y;
int dp[20][20][20][20];
int dfs(int x1, int y1, int x2, int y2) {
	if (x1 == n && y1 == n && x2 == n && y2 == n) {
		return a[n][n];
	}
	int &ans = dp[x1][y1][x2][y2];
	if (ans == -1) {
		ans = 0;
		if (x1 < n && x2 < n)
			ans = max(ans, dfs(x1 + 1, y1, x2 + 1, y2));
		if (x1 < n && y2 < n)
			ans = max(ans, dfs(x1 + 1, y1, x2, y2 + 1));
		if (y1 < n && x2 < n)
			ans = max(ans, dfs(x1, y1 + 1, x2 + 1, y2));
		if (y1 < n && y2 < n)
			ans = max(ans, dfs(x1, y1 + 1, x2, y2 + 1));
		ans += a[x1][y1];
		if (x1 != x2 || y1 != y2)
			ans += a[x2][y2];
	}
	return ans;
}
int main() {
	scanf("%d", &n);
	while (scanf("%d%d%d", &x, &y, &m)) {
		if (x != 0 && y != 0 && m != 0) {
			a[x][y] = m;
		} else {
			break;
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d", dfs(1, 1, 1, 1));
	return 0;
}
