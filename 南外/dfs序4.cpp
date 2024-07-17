#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int f[20][N], c[N], d[N], be[N], en[N];
int tot, s, t;
vector<int> g[N];
int i, j, n, m;
void dfs(int x, int fa) {
	be[x] = ++tot;
	d[x] = d[fa] + 1;
	f[0][x] = fa;
	for (int i1 = 1; i1 <= t; i1++) {
		f[i1][x] = f[i1 - 1][f[i1 - 1][x]];
	}
	for (auto y : g[x]) {
		if (y == fa)
			continue;
		dfs(y, x);
	}
	en[x] = tot;
	return;
}
int lca(int x, int y) {
	if (d[x] > d[y]) {
		swap(x, y);
	}
	for (int i1 = t; i1 >= 0; i1--) {
		if (d[f[i1][y]] >= d[x]) {
			y = f[i1][y];
		}
	}
	if (x == y)
		return x;
	for (int i1 = t; i1 >= 0; i1--) {
		if (f[i1][x] != f[i1][y]) {
			x = f[i1][x];
			y = f[i1][y];
		}
	}
	return f[0][x];
}
int lowbit(int x) { return x & -x; }
void add(int x, int w) {
	for (; x <= n; x += lowbit(x)) {
		c[x] += w;
	}
	return;
}
int qry(int x) {
	int res = 0;
	for (; x; x -= lowbit(x)) {
		res += c[x];
	}
	return res;
}
int main() {
	scanf("%d%d", &n, &m);
	t = log2(n) + 1;
	for (i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	while (m--) {
		int op, u, v;
		scanf("%d%d%d", &op, &u, &v);
		if (op == 1) {
			add(be[u], v);
			add(en[u] + 1, -v);
		} else {
			int fa = lca(u, v);
			printf("%d\n", qry(be[u]) + qry(be[v]) - qry(be[fa]) - qry(be[f[0][fa]]));
		}
	}
	return 0;
}
