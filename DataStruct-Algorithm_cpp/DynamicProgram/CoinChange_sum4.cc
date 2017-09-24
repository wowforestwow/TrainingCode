/*Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
		vector<int> dp(target+1, 0);
		dp[0] = 1;
		//int count = 0;
		for(int i = 1; i <= target; i++) {
			//vector<int> tmp;
			int sum = 0;
			//count = 0;
			for(auto num : nums) {
				if(i-num >= 0 && dp[i-num] >= 0){
					sum += dp[i-num];
					//count++;
				}
			}
			int count = 0;
			for(int i1 = 0; i1 < nums.size(); i1++) {
				for(int j = i1 + 1; j < nums.size(); j++) {
					if(nums[i1] + nums[j] == i)
						count++;
				}
			}
			if(sum > 0)
				dp[i] = sum - count;
			else
				dp[i] = 0;
		}
		return dp[target];
    }
};


int main() {
	vector<int> a1 = {5, 10, 25,1};
	vector<int> a2 = {3, 5};
	Solution s;
	cout << s.combinationSum4(a1, 10) << endl;
	//cout <<	s.combinationSum4(a2, 2) << endl;

}
