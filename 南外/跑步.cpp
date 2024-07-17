#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, t;
int a[110], x, y, flag;
int mark[105][10005];
void dfs(int ma, int mi, int step, int sd) {
	if (mark[sd][step] == 1 || flag == 1)
		return;
	if (sd > n) {
		flag = 1;
		return;
	}
	if (step + a[sd] <= m) {
		dfs(step + a[sd], mi, step + a[sd], sd + 1);
		mark[sd + 1][step + a[sd]] = 1;
	}
	if (step - a[sd] >= 0) {
		dfs(ma, step - a[sd], step - a[sd], sd + 1);
		mark[sd + 1][step - a[sd]] = 1;
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(mark, 0, sizeof(mark));
		scanf("%d%d", &m, &n);  //[0,m]
		for (i = 1; i <= n; i++) {
			scanf("%d%d", &x, &y);
			a[i] = y - x;
		}
		flag = 0;
		for (i = 1; i <= m; i++) dfs(0, 0, i, 1);
		if (flag == 1)
			printf("possible\n");
		else
			printf("impossible\n");
	}
	return 0;
}
