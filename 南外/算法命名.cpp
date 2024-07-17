#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int ans;
string s, s1;
int main() {
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s1[++j] = s[i];
		}
	}
	for (i = 1; i <= j; i++) {
		cout << s1[i];
	}
	return 0;
}
