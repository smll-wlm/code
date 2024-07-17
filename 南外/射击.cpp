#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
string s;
int a[10];
long long ans;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		char c = getchar();
		if (c >= '0' && c <= '9')
			s += c;
		else
			i--;
	}
	for (i = 0; i < n; i++) {
		a[s[i] - '0']++;
	}
	for (i = 0; i < 10; i++) {
		int x = a[i];
		if (x != 0)
			ans += x * (x - 1) / 2;
	}
	printf("%lld", ans);
	return 0;
}
