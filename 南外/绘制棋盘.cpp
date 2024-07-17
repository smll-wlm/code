#include <bits/stdc++.h>
using namespace std;
int i, j, n, m, n1, m1;
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &n1, &m1);
	char c = 'X';
	int i1, j1;
	for (i = 1; i <= n; i++) {
		for (i1 = 1; i1 <= n1; i1++) {
			for (j = 1; j <= m; j++) {
				for (j1 = 1; j1 <= m1; j1++) {
					if ((i + j) % 2 == 0)
						c = 'X';
					else
						c = '.';
					printf("%c", c);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
