#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<cstring>
#include<memory>

using namespace std;

int main(){
	string str = "hel";
	const char* tmp = str.c_str();
	//string tmp = str;
	do {
		cout << tmp[0] << tmp[1] << tmp[2] << endl;
	} while (next_permutation(tmp, tmp+2));

	//int myints[] = {1, 2, 3};
	char myints[] = {'a', 'b','c'};
	sort(myints, myints+3);

	cout << "possible permutation: \n";
	do {
		cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
	} while (next_permutation(myints, myints+3));
	cout << "after loop:" << myints << endl;
	for(auto i : myints)
		cout << i << " " << endl;
	vector<int> vec = {1, 2, 3};
	for (auto i : vec)
		cout << i << " " << endl;
	for (auto iter = vec.cbegin(); iter != vec.cend(); iter++)
		cout << * iter << ' ' ;
	return 1;
}
