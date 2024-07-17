#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, k, tot[N], ans, d[N], t[N];
int ver[N], nex[N], head[N], total;
queue<int> q;
void add(int a, int b) {
	ver[++total] = b;
	nex[total] = head[a];
	head[a] = total;
}
int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		d[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) {
		tot[i] = t[i];
		q.push(i);
	}
	while (q.size() != 0) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i != -1; i = nex[i]) {
			int y = ver[i];
			d[y]--;
			tot[y] = max(tot[y], tot[x] + t[y]);
			if (d[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= n; i++) ans = max(ans, tot[i]);
	printf("%d\n", ans);
	return 0;
}
