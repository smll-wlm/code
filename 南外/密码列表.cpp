#include <bits/stdc++.h>
using namespace std;
int i, j, n, m;
struct node {
	int bh;
	string s;
	int len;
} a[110];
bool cmp(node x, node y) { return x.len < y.len; }
long long ans;
int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		/*char c=getchar();
        if(c>='a'&&c<='z')
        {
                cout<<c<<' ';
                a[i].s+=c;
                getline(cin,a[i].s);


        }
        else{
                i--;
        }*/
		cin >> a[i].s;
		a[i].bh = i;
		a[i].len = a[i].s.size();
	}
	int flag = 1;
	sort(a + 1, a + 1 + n, cmp);
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (a[i].len == a[j].len) {
				flag = 1;
				for (int i1 = 0, j1 = a[j].len - 1; i1 < a[i].len; i1++, j1--) {
					if (a[i].s[i1] != a[j].s[j1]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					printf("%d ", a[i].len);
					cout << a[i].s[a[i].len >> 1];
				}
			} else
				break;
		}
	}
	return 0;
}
