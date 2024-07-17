#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int ans;
string s;
int main() {
	cin >> s;
	int len = s.size();
	for (i = 0; i < len; i++) {
		if (s[i] >= 'A' && s[i] <= 'C')
			ans += 3;
		if (s[i] >= 'D' && s[i] <= 'F')
			ans += 4;
		if (s[i] >= 'G' && s[i] <= 'I')
			ans += 5;
		if (s[i] >= 'J' && s[i] <= 'L')
			ans += 6;
		if (s[i] >= 'M' && s[i] <= 'O')
			ans += 7;
		if (s[i] >= 'P' && s[i] <= 'S')
			ans += 8;
		if (s[i] >= 'T' && s[i] <= 'V')
			ans += 9;
		if (s[i] >= 'W' && s[i] <= 'Z')
			ans += 10;
	}
	printf("%d", ans);
	return 0;
}
