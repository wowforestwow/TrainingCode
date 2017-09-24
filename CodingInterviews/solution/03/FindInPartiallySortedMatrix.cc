#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {

    }
};

int main(){
	//int matrix[][4] = {{{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	vector<vector<int>> matrix = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	Solution s;
	if(s.Find(7,matrix)){
		cout << "ok!";
	}else{
		cout << "false!";
	}
	if(s.Find(5,matrix)){
		cout << "ok!";
	}else{
		cout << "false!";
	}

}
