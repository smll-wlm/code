#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int i, j, n, m, k;
int A[N];
struct node {
	int l, r, lm, rm, mx;
} tr[4 * N];
void pushup(node &a, node b, node c) {
	a.lm = b.lm, a.rm = c.rm;
	a.mx = max(b.mx, c.mx);
	if (A[b.r] != A[c.l]) {
		a.mx = max(a.mx, b.rm + c.lm);
		if (b.lm == b.r - b.l + 1)
			a.lm += c.lm;
		if (c.lm == c.r - c.l + 1)
			a.rm += b.rm;
	}
	return;
}
void build(int l, int r, int p) {
	tr[p].l = l, tr[p].r = r;
	tr[p].mx = tr[p].lm = tr[p].rm = 1;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(l, mid, p << 1);
	build(mid + 1, r, p << 1 | 1);
}
void update(int x, int p) {
	if (tr[p].l == tr[p].r) {
		A[x] ^= 1;
		return;
	}
	int mid = tr[p].l + tr[p].r >> 1;
	if (mid >= x)
		update(x, p << 1);
	else
		update(x, p << 1 | 1);
	pushup(tr[p], tr[p << 1], tr[p << 1 | 1]);
}
int main() {
	scanf("%d%d", &n, &k);
	build(1, n, 1);
	while (k--) {
		int x;
		scanf("%d", &x);
		update(x, 1);
		printf("%d\n", tr[1].mx);
	}
	return 0;
}
