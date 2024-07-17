#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
string s;
int a[100010][5], b[30][30];
long long ans;
void dfs(int step, int chu, long long num) {
	if (step == 4) {
		num = num * b[i][chu];
		ans += num;
		return;
	}
	if (step == 1 || step == 2) {
		for (int k = 1; k <= 26; k++) {
			if (b[chu][k] != 0) {
				b[chu][k]--;
				dfs(step + 1, k, num * (b[chu][k] + 1));
				b[chu][k]++;
			}
		}
	} else {
		for (int k = 1; k <= 26; k++) {
			if (b[k][chu] != 0) {
				b[k][chu]--;
				dfs(step + 1, k, num * (b[k][chu] + 1));
				b[k][chu]++;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		cin >> s;
		a[i][1] = s[0] - 'A' + 1;
		a[i][2] = s[s.size() - 1] - 'A' + 1;
		b[a[i][1]][a[i][2]]++;
	}
	for (i = 1; i <= 26; i++) dfs(1, i, 1);
	printf("%lld", ans);
	return 0;
}
