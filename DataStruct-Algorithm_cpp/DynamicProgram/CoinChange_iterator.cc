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
		vector<int> dp(amount+1, 0);
		for(int i = 1; i <= amount; i++) {
			vector<int> tmp;
			for(int coin : coins) {
				if(i-coin >= 0 && dp[i-coin]>=0){
					tmp.push_back(dp[i-coin]);
				}
			}
			if(tmp.size() > 0)
				dp[i] = *min_element(tmp.begin(),tmp.end()) + 1;
			else
				dp[i] = -1;
			tmp.clear();
		}
		cout << dp[amount];
		return dp[amount];
	}
};

int main() {
	vector<int> a = {5, 2, 3};
	vector<int> a3 = {3, 5};
	Solution s;
	cout << s.coinChange(a, 20) << endl;
	cout << s.coinChange(a3, 2)  << endl;
}
