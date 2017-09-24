#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
		if(number == 1)
			return 1;
		if(number == 2)
			return 2;

		vector<int> count(number, 0);
		count[0] = 1;
		count[1] = 2;
		for(int i = 2; i < number; i++){
			int sum = 0;
			for(int j = 0; j < i; j++){
				sum += count[j];
			}
			count[i] = sum+1; // add itself
		}
		return count[number-1];
    }
};

int main(){
	Solution s;
	cout << s.jumpFloorII(4) << endl ;
}
