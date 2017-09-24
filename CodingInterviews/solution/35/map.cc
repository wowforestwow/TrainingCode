#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> m1;
	//m1 = {1:1, 2:2};
	//显示初始化的方式就这一种
	m1[1] = 1;
	map<int, int> m2 = m1;
	cout << endl;
   /* int myints[] = {1, 2, 3};*/
	//vector<int> v1{myints,myints+3};

	// map是一个有序的存储结构，故可以泛化比较函数
	map<char, int> first;
	first['a'] = 10;
	first['b'] = 20;
	first['c'] = 30;
	first['d'] = 40;


}

