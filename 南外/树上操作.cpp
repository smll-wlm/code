#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
const int magic = 12347;
int i, j, n, m, q;
long long ans[N], sum[N], hsh;
vector<int> v[N];
struct node {
	int l, r, v, nxt;
} b[N];
int a[N], cnt;
void dfs(int x, int dep, long long w) {
	for (int k = a[x]; k; k = b[k].nxt) {
		node j1 = b[k];
		if (j1.r >= dep) {
			sum[max(dep, j1.l)] += j1.v;
			sum[j1.r + 1] -= j1.v;
		}
	}
	w += sum[dep];
	ans[x] = w;
	for (auto it : v[x]) dfs(it, dep + 1, w);
	for (int i1 = a[x]; i1; i1 = b[i1].nxt) {
		node j1 = b[i1];
		if (j1.r >= dep) {
			sum[max(dep, j1.l)] -= j1.v;
			sum[j1.r + 1] += j1.v;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		v[x].push_back(i);
	}
	scanf("%d", &q);
	while (q--) {
		int p1, l1, r1, v1;
		scanf("%d%d%d%d", &p1, &l1, &r1, &v1);
		b[++cnt] = { l1, r1, v1, a[p1] };
		a[p1] = cnt;
	}
	dfs(1, 1, 0);
	for (i = 1; i <= n; i++) {
		hsh = (hsh * magic + ans[i]) % mod;
	}
	printf("%lld", hsh);
	return 0;
}
