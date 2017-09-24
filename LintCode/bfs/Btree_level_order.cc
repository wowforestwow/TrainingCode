/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
#include<bits/stdc++.h>
#include<queue>

using namespace std;

class Solution {
  public:
    /*
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
		vector<vector<int>> res;

		if(root == NULL){
			return res;
		}
		queue<TreeNode *> que;
		que.push(root);
		while(!que.empty()){
			int length = que.size();
			vector<int> level;

			for(int i = 0; i < length; i++){
				TreeNode *value = que.front();
				que.pop();
				level.push_back(value->val);
				if(value->left != NULL){
					que.push(value->left);
				}
				if(value->right != NULL){
					que.push(value->right);
				}
			}

			res.push_back(level);
			//level.clear();
		}
		return res;
    }
};
