/*You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
test website:https://leetcode.com/problems/coin-change/description/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		if(amount < 0)
			return -1;
		if(amount == 0)
			return 0;
		int min = numeric_limits<int>::max();
		//int min = 1000;
		int count = 0;
		for(auto i : coins){
			int tmp = coinChange(coins, amount - i);
			//从合法状态中取出来，tmp>=0
			if(tmp >= 0 && tmp < min)
				min = tmp;
			if(tmp < 0) {
				count++;
			}
		}
		if(count == coins.size())
			return -1;
		else
			return min + 1;

    }
};

int main() {
	vector<int> a = {5, 2, 3};
	vector<int> a3 = {3, 5};
	Solution s;
	cout << s.coinChange(a, 20) << endl;
	//cout << s.coinChange(a3, 2)  << endl;
}
