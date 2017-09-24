//此版本认为从1位开始，1 1 2
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int Fibonacci(int n){
		if (n == 1)      //0版本1改为0
			return 1;    // return 0
		if (n == 2)
			return 1;

		int f1 = 1;       //1改为0
		int f2 = 1;
		int f3;
		int count = n - 2;  // 减1
		while(count--){
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};

int main(){
	Solution s;
	cout << s.Fibonacci(3) << endl;
	cout << s.Fibonacci(39) << endl;
}
