#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
   /* void jumpcount(int state, int &count, int target){*/
		//if(state == target){
			//count++;
			//return;
		//}
		//if(state > target)
			//return;
		//jumpcount(state+1,count,target);
		//jumpcount(state+2,count,target);

	//}
    //int jumpFloor(int number) {
		//int target = number;
		//int count = 0;
		//jumpcount(0, count, target);
		//return count;
    /*}*/

	int jumpFloor(int number) {
		if(number == 1)
			return 1;
		if( number == 2)
			return 2;
		int f1 = 1;
		int f2 = 2;
		int f3;
		int count = number;
		count -= 2;
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
	cout << s.jumpFloor(4) << endl;
}
