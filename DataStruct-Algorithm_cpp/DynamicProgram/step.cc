#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int m;
	while(n-- > 0) {
		cin >> m;
		if(m == 1) {
			cout << 0 << endl;
			continue;
		}
		if(m == 2) {
			cout << 1 << endl;
			continue;
		}
		if(m == 3) {
			cout << 2 << endl;
			continue;
		}
		int f2 = 1;
		int f3 = 2;
		int f4 = 0;
		int count = m - 3;
		while(count--) {
			f4 = f3 + f2;
			f2 = f3;
			f3 = f4;
		}
		cout << f4 << endl;
	}
}
