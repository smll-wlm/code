#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
string s;
char c[310];
int ans;
int main() {
	getline(cin, s);
	for (i = 0; i < s.size(); i++) {
		c[i + 1] = s[i];
	}
	int len = s.size();
	for (i = 1; i <= len; i++) {
		if (i % 3 == 1 && c[i] != 'P')
			ans++;
		if (i % 3 == 2 && c[i] != 'E')
			ans++;
		if (i % 3 == 0 && c[i] != 'R')
			ans++;
	}
	printf("%d", ans);
	return 0;
}
