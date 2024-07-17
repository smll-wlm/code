#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
string s;
int prime[10010], mark[10010], prm[10010], num[10010];
int a[30], s1[20010], p;
long long ans;
void init() {
	for (i = 2; i <= 10000; i++) {
		if (!mark[i]) {
			prime[p++] = i;
			for (j = i + i; j <= 10000; j += i) {
				mark[j] = 1;
			}
		}
	}
}
void f(int n1, int k) {
	for (int i1 = 0; i1 < p && prime[i1] <= n1; i1++) {
		int x = prime[i1];
		while (x <= n1) {
			prm[i1] += n1 / x * k;
			x *= prime[i1];
		}
	}
}
int main() {
	cin >> s;
	s = " " + s;
	init();
	int len = s.size() - 1;
	for (i = 1; i <= len; i++) {
		s1[i] = s[i] - 'A' + 1;
		a[s1[i]]++;
	}
	int flag = 0, tot = 0;
	;
	for (i = 1; i <= 26; i++) {
		if (a[i] % 2 == 1)
			flag++;
		a[i] /= 2;
		tot += a[i];
	}
	if (flag > 1) {
		printf("0");
		return 0;
	}
	f(tot, 1);
	for (i = 1; i <= 26; i++) {
		if (a[i] > 1)
			f(a[i], -1);
	}
	num[0] = 1;
	n = 1;
	for (i = 0; i < p; i++) {
		if (prm[i] > 0) {
			for (j = 0; j < prm[i]; j++) {
				for (int k = 0; k < n; k++) num[k] = num[k] * prime[i];
				for (int k = 0; k < n; k++) {
					if (num[k] >= 10000) {
						num[k + 1] += num[k] / 10000;
						num[k] %= 10000;
					}
				}
				if (num[n] > 0)
					n++;
			}
		}
	}
	printf("%d", num[n - 1]);
	for (i = n - 2; i >= 0; i--) printf("%04d", num[i]);
	return 0;
}
