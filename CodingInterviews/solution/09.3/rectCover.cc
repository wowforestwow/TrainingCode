#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rectCover(int number) {
		// consider unlegal situation
		if(number <= 0)
			return 0;
		if(number == 1)
			return 1;
		if(number == 2)
			return 2;
		int f1 = 1;
		int f2 = 2;
		int f3 = 0;
		int count = number - 2;
		while(count--) {
			f3 = f2 + f1;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};

int main(){
	Solution s;
	cout << s.rectCover(6) << endl;

}
