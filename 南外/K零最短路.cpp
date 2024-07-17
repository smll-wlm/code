#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, k, s, t;
struct edge {
	int v, w;
	bool operator<(const edge &a) const { return this->w > a.w; }
};
struct node {
	int v, w, p;
	bool operator<(const node &a) const { return this->w > a.w; }
};
vector<edge> g[10010];
int d[20][10010];
bool vis[20][10010];
void dij(int s) {
	memset(d, 0x3f, sizeof(d));
	d[0][s] = 0;
	priority_queue<node> pq;
	pq.push((node){ s, 0, 0 });
	while (!pq.empty()) {
		node tmp = pq.top();
		pq.pop();
		int u = tmp.v;
		int w = tmp.w;
		int p = tmp.p;
		if (vis[p][u])
			continue;
		vis[p][u] = true;
		d[p][u] = w;
		for (j = 0; j < g[u].size(); j++) {
			int ed = g[u][j].v;
			int wed = g[u][j].w + w;
			if (!vis[p][ed]) {
				pq.push((node){ ed, wed, p });
			}
			if (p + 1 <= k && !vis[p + 1][ed]) {
				pq.push((node){ ed, w, p + 1 });
			}
		}
	}
	return;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &s, &t);
	for (i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back((edge){ v, w });
		g[v].push_back((edge){ u, w });
	}
	dij(s);
	printf("%d", d[k][t]);
	return 0;
}
