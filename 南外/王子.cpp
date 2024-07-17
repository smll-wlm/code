#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node {
	int id, h;
};
int n, m, a[N], ans[N], t[N];
vector<int> v[N];
vector<node> q[N];
void dfs(int x, int pre, int d) {
	for (auto it : q[x]) {
		ans[it.id] = t[d + it.h + 1];
	}
	for (auto i : v[x]) {
		if (i == pre) {
			continue;
		}
		dfs(i, x, d + 1);
		a[x] += a[i];
	}
	t[d] += a[x];
	for (auto i : q[x]) {
		ans[i.id] += a[x] - t[d + i.h + 1];
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		int x, h;
		scanf("%d%d", &x, &h);
		q[x].push_back({ i, h });
	}
	dfs(1, 0, 1);
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}
