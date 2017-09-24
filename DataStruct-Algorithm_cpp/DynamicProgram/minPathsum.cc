/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

 Notice

You can only move either down or right at any point in time.
test web site : http://www.lintcode.com/en/problem/minimum-path-sum/  */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * @param grid: a list of lists of integers
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int>> &grid) {
        // write your code here
		int n = grid[0].size();
		int m = grid.size();
		int i = 0;
		for(int j = 1; j < n; j++)
			grid[i][j] +=  grid[i][j-1];
		int j = 0;
		for(int i = 1; i < m; i++)
			grid[i][j] += grid[i-1][j];
		for(int i = 1; i < m; i++) {
			for(int j = 1; j < n; j++)	{
				grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
			}
		}
		return grid[m-1][n-1];
    }
};

int main() {
	vector<vector<int>> a = {{1, 3, 5, 9}, {8, 1, 3, 4}, {5, 0, 6, 1}, {8,8, 4, 0}};
	Solution s;
	cout << s.minPathSum(a);

}
