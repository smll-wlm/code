#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
const int M = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int n, m, idx;
int w[N], to[N], vis[N], nex[N], dis[N], now[N], cnt[N];

void add(int x, int y, int z) {
	to[idx] = y;
	w[idx] = z;
	nex[idx] = now[x];
	now[x] = idx++;
}

int spfa() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
		vis[i] = 1;
	}
	while (q.size()) {
		int f = q.front();
		q.pop();
		vis[f] = 0;
		for (int i = now[f]; i != -1; i = nex[i]) {
			int j = to[i];
			if (dis[j] > dis[f] + w[i]) {
				dis[j] = dis[f] + w[i];
				cnt[j] = cnt[f] + 1;
				if (cnt[j] >= n)
					return 1;
				if (!vis[j]) {
					vis[j] = 1;
					q.push(j);
				}
			}
		}
	}
	return 0;
}

int main() {
	fill(dis, dis + N, inf);
	fill(now, now + N, -1);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	if (spfa()) {
		cout << "YES" << endl;
	} else
		cout << "NO" << endl;
}
