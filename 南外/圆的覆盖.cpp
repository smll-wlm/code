#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, n1, m1, ans;
int mx, sqr[10010];
multiset<int> st[10010];
struct node {
	int x, y, r;
} cir[20010];
struct node2 {
	int x, y, flag;
} poi[100010];
void read() {}
template <typename T, typename... T2>
inline void read(T &x, T2 &... oth) {
	x = 0;
	int ch = getchar(), f = 0;
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = 1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	if (f)
		x = -x;
	read(oth...);
}

inline void write(int a) {
	if (a < 0)
		putchar('-'), a = -a;
	if (a >= 10)
		write(a / 10);
	putchar(a % 10 + 48);
}
int main() {
	read(n);
	for (i = 1; i <= n; i++) {
		read(poi[i].x, poi[i].y);
		st[poi[i].x].insert(poi[i].y);
		mx = max(mx, poi[i].x);
	}
	for (i = 1; i <= 10000; i++) {
		int x = sqrt(i);
		if (x * x == i)
			sqr[i] = x;
		else
			sqr[i] = sqr[i - 1];
	}
	read(m);
	for (i = 1; i <= m; i++) {
		read(cir[i].x, cir[i].y, cir[i].r);
		int l = max(0, cir[i].x - cir[i].r), r = min(mx, cir[i].x + cir[i].r), mr = cir[i].r * cir[i].r;
		for (j = l; j <= r; j++) {
			int l0 = abs(j - cir[i].x);
			l0 *= l0;
			int res = sqr[mr - l0];
			auto it1 = st[j].lower_bound(cir[i].y - res);
			auto it2 = st[j].upper_bound(cir[i].y + res);
			st[j].erase(it1, it2);
		}
	}
	for (i = 0; i <= 10000; i++) {
		ans += st[i].size();
	}
	write(ans);
	return 0;
}
