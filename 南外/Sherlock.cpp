#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, n1, m1;
string s;
int cnt, ans, flag;
char c[310];
int main() {
	scanf("%s", c + 1);
	int maxn = 0, minn = 0;
	int len = strlen(c + 1);
	for (i = 1; i <= len; i++) {
		if (c[i] == '+') {
			cnt++;
			
		} else {
			cnt--;
		}
		maxn = max(maxn, cnt);
		minn = min(minn, cnt);
	}
	printf("%d", maxn - minn);
	return 0;
}
