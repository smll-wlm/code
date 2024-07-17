#include <bits/stdc++.h>
#define int long long
using namespace std;
int i, j, n, m;
int k, ans;
signed main() {
	scanf("%d%d", &n, &m);
	k = pow(10, m);
	int n1 = n / k;
	int n2 = n1 + 1;
	int n3, n4;
	n3 = n % k;
	n4 = n2 * k - n;
	if (n3 < n4) {
		printf("%d", k * n1);
	} else {
		printf("%d", k * n2);
	}
	return 0;
}
