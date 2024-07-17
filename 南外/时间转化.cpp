#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int h, s;
int main() {
	scanf("%d", &n);
	h = n / 3600;
	n %= 3600;
	m = n / 60;
	n %= 60;
	s = n;
	printf("%d:%d:%d", h, m, s);
	return 0;
}
