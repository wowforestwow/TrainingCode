#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int FirstNotRepeatingChar(string str) {
		map<char,int> m;
		for(char c:str) {
			m[c] = m[c]+1;
		}
		char select;
		for(auto it = m.begin(); it != m.end(); it++) {
			if(it->second == 1) {
				select = it->first;
				break;
			}
		}
		int count = 0;
		for(char c:str) {
			if(c == select)
				return count;
			count++;
		}
		return -1;
    }
};

int main() {
	fstream cin("input.txt");
	ofstream cout("output.txt");
	string str;
	while(cin >> str) {
		Solution s;
		cout << s.FirstNotRepeatingChar(str) << endl;
	}
}
