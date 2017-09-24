#include <bits/stdc++.h>

using namespace std;

int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int dfs(vector<vector<int>> &a, vector<vector<int>> &f, int i, int j) {
	if(f[i][j] != -1)
		return f[i][j];
	f[i][j] = 0;
	for(int c = 0; c < 4; c++){
		int dx = direction[i][0];
		int dy = direction[i][1];
		if(a[i][j] < a[i+dx][j+dy]) {
			f[i][j] = max(f[i][j], dfs(a, f, i+dx, j+dy));
		}
	}
	return ++f[i][j];

}


int main() {
	int number;
	fstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> number;
	while(number--) {
		string str;
		int row = 0, col = 0;
		cin >> str >> row >> col;
		//cout << row << col << endl;
		//int tmp;
		vector<vector<int>> a(row+2, vector<int>(col+2));
		vector<vector<int>> f(row+2, vector<int>(col+2));
		for(int i = 0; i < row+2; i++) {
			a[i][0] = a[i][col+1] = numeric_limits<int>::max();
		}
		for(int j = 0; j < col+2; j++) {
			a[0][j] = a[row+1][j] = numeric_limits<int>::max();
		}
		int t[10];
		memset(t, -1, sizeof(t));
	//	memset(f, -1, sizeof(f));
		for(auto &i : f)
			for(auto &j : i)
				j = -1;

		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= col; j++) {
				cin >> a[i][j];
			}
		}
		//cout << endl;

		int res = -1;
		for(int i = 1; i <= row; i++) {
			for(int j = 1; j <= col; j++) {
				res = max(res, dfs(a, f, i, j));
			}
		}
		cout << res << endl;
	}
}
