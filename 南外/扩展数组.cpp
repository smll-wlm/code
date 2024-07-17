#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
int k;
string s;
int a[110];
long long ans;
void print_k(int k1) {
	for (j = 1; j <= k1; j++) {
		printf(" ");
	}
	return;
}
int main() {
	getline(cin, s);
	int len = s.size();
	k = 0;
	int flag = 0;
	for (i = 0; i < len; i++) {
		if (s[i] == ',') {
			printf(",\n");
			flag = 1;
			continue;
		}
		if (s[i] == '{') {
			print_k(k);
			printf("{\n");
			flag = 1;
			k += 2;
			continue;
		}
		if (s[i] == '}') {
			print_k(k - 2);
			printf("}");
			k -= 2;
			if (s[i + 1] != ',')
				printf("\n");
			continue;
		} else {
			if (flag == 1) {
				print_k(k);
				flag = 0;
			}
			cout << s[i];
			if (s[i + 1] == '}')
				printf("\n");
		}
	}
	return 0;
}
