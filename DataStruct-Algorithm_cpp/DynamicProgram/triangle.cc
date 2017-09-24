#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
     * @param triangle: a list of lists of integers
     * @return: An integer, minimum path sum
     */
    int minimumTotal(vector<vector<int>> &triangle) {
        // write your code here
		int row = triangle.size();
		int column = triangle[row-1].size();
   /*     int column = triangle[3].size();*/
		//vector<vector<int> > cost(row, vector<int>(column));
		/*vector<vector<int> > answer;*/
		vector<vector<int> > answer(row, vector<int>(column));
		int tmp = triangle[0][0];
		answer[0][0] = tmp;
		for(int i = 1; i < row; i++){
			//for(int j = 0; j < triangle[i].size(); j++)	{
			for(int j = 0; j <= i; j++)	{   //加了等号
				vector<int> tmp;
				if(i-1 >=0 && j-1 >=0) {
					// 添加的值是改变了answer的值，非原来本身
					tmp.push_back(answer[i-1][j-1]);
				}
				if(i-1 >=0 && j <= i-1) {
					tmp.push_back(answer[i-1][j]);
				}
				int min = *min_element(tmp.begin(),tmp.end());
				answer[i][j] = min + triangle[i][j];
			}
		}
		int i = answer.size()-1;
		//int j = answer[i].size();
		int min = *min_element(answer[i].begin(),answer[i].end());
		//for(int i = 0; i < kk)

		//cout << min;

		return min;



    }
};


int main() {
	vector<vector<int> > a = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	Solution s;
	s.minimumTotal(a);
}
