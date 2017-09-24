#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
		 int length = sizeof(int) * 8;
		 int compare = 1;
		 int count = 0;
		 for(int i = length; i >= 1; i--) {
			 // 注意& priority
			if( (n & compare) != 0)
				count++;
			compare = compare << 1;
		 }
		return count;
     }
};

int main() {
	Solution s;
	cout << s.NumberOf1(4) << endl;
	cout << s.NumberOf1(-1) << endl;

}
