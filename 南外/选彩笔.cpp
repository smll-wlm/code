#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
const int M = 257;
int f, n, m, l = 1, r, ansr, ansg, ansb;
int a[N][3], s[M][M][M];
int i, j;
int sum(int x, int y, int z, int l) {
	int res = s[x][y][z];
	res -= s[x - l][y][z] + s[x][y - l][z] + s[x][y][z - l];
	res += s[x - l][y - l][z] + s[x][y - l][z - l] + s[x - l][y][z - l];
	res -= s[x - l][y - l][z - l];
	return res;
}
bool check(int mid) {
	for (int r = mid; r <= f; r++) {
		for (int g = mid; g <= f; g++) {
			for (int b = mid; b <= f; b++) {
				if (sum(r, g, b, mid) >= m) {
					ansr = r;
					ansg = g, ansb = b;
					return 1;
				}
			}
		}
	}
	return 0;
}
int pd(int x, int y, int z) {
	if (x <= ansr && y <= ansg && z <= ansb && x > ansr - l && y > ansg - l && z > ansb - l) {
		return 1;
	}
	return 0;
}
signed main() {
	//	freopen("color10.in","r",stdin);
	//	freopen("color10.out","w",stdout);
	scanf("%lld %lld", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%lld%lld%lld", &a[i][1], &a[i][2], &a[i][3]);
		s[++a[i][1]][++a[i][2]][++a[i][3]]++;
		for (j = 1; j <= 3; j++) {
			f = max(f, a[i][j]);
		}
	}
	for (int x = 1; x <= f; x++) {
		for (int y = 1; y <= f; y++) {
			for (int z = 1; z <= f; z++) {
				s[x][y][z] += s[x][y][z - 1];
			}
		}
	}
	for (int x = 1; x <= f; x++) {
		for (int y = 1; y <= f; y++) {
			for (int z = 1; z <= f; z++) {
				s[x][y][z] += s[x][y - 1][z];
			}
		}
	}
	for (int x = 1; x <= f; x++) {
		for (int y = 1; y <= f; y++) {
			for (int z = 1; z <= f; z++) {
				s[x][y][z] += s[x - 1][y][z];
			}
		}
	}
	r = f + 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%lld\n", l - 1);
	for (i = 1; i <= n; i++) {
		if (pd(a[i][1], a[i][2], a[i][3])) {
			printf("%lld %lld %lld\n", a[i][1] - 1, a[i][2] - 1, a[i][3] - 1);
		}
	}
	return 0;
}
