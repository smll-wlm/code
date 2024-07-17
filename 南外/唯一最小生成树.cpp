#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int fa[1010], f[50010];
struct node {
	int u, v, w;
} e[50010];
bool cmp(node x, node y) { return x.w < y.w; }
int find(int u) {
	if (fa[u] == u)
		return u;
	return fa[u] = find(fa[u]);
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= m; i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
		sort(e + 1, e + 1 + m, cmp);
		for (i = 1; i <= n; i++) {
			fa[i] = i;
		}
		int ans = 0;
		bool flag = 1;
		int x = 0;
		for (i = 1; i <= m;) {
			j = i + 1;
			while (j <= m && e[i].w == e[j].w) j++;
			int cnt = 0;
			for (int k = i; k < j; k++) {
				if (find(e[k].u) != find(e[k].v))
					cnt++;
			}
			for (int k = i; k < j; k++) {
				int u = find(e[k].u);
				int v = find(e[k].v);
				if (u != v) {
					cnt--;
					fa[u] = v;
					ans += e[k].w;
				}
			}
			if (cnt)
				flag = 0;
			i = j;
		}
		if (flag)
			printf("%d\n", ans);
		else
			printf("Not Unique!\n");
	}
	return 0;
}
