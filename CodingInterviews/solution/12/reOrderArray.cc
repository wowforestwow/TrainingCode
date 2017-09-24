#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> oven;
		//注意从-1开始计算
		int odd = -1;
		for(int i = 0; i < array.size(); i++) {
			if(array[i] % 2 == 1) {
				odd++;
				if(odd != i)
					array[odd] = std::move(array[i]);
			}else{
				oven.push_back(array[i]);
			}
		}
		//odd加号在前，才是先加一
		for(int i = ++odd, j = 0; i < array.size(); i++,j++)
			array[i] = oven[j];

	}
};

void print(vector<int> &vec) {
	for(int i : vec)
		cout << i << " " ;
	cout << endl;
}

int main() {
	Solution s;
	vector<int> vec = {1, 2, 3, 4, 5};
	vector<int> vec1 = {2, 4, 5, 7, 6};
	s.reOrderArray(vec);
	s.reOrderArray(vec1);
	print(vec);
	print(vec1);
}
