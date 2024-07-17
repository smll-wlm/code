#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int ans;
int main() {
	int n1, n2, n3;
	char c1, c2;
	scanf("%d %c %d %c %d", &n1, &c1, &n2, &c2, &n3);
	if ((c1 == '+' || c1 == '-') && (c2 == '*' || c2 == '/' || c2 == '%')) {
		if (c2 == '*') {
			ans += n2 * n3;
		} else if (c2 == '/') {
			ans += n2 / n3;
		} else
			ans += n2 % n3;
		switch (c1) {
			case '+': {
				ans += n1;
				break;
			}
			case '-': {
				ans = n1 - ans;
				break;
			}
		}
		printf("%d", ans);
		return 0;
	}
	switch (c1) {
	case '+':
		ans = n1 + n2;
		break;
	case '-':
		ans = n1 - n2;
		break;
	case '*':
		ans = n1 * n2;
		break;
	case '/':
		ans = n1 / n2;
		break;
	case '%':
		ans = n1 % n2;
		break;
	}
	switch (c2) {
	case '+':
		ans = ans + n3;
		break;
	case '-':
		ans = ans - n3;
		break;
	case '*':
		ans = ans * n3;
		break;
	case '/':
		ans = ans / n3;
		break;
	case '%':
		ans = ans % n3;
		break;
	}
	printf("%d", ans);
	return 0;
}
