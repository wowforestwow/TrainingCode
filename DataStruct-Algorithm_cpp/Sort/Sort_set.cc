#include <iostream>
#include <vector>

using namespace std;


template<typename object>
void Insert_sort(vector<object> & a){
	for(int i = 1; i < a.size(); i++) {
		object tmp = a[i];
		int j = i;
		for(j = i-1; j >= 0 && a[j] > tmp; j--){
			//std::swap(a[j-1], a[j]);
			a[j+1] = std::move(a[j]);
		}
		a[j+1] = std::move(tmp);
	}
}

template<typename object>
void print(vector<object> &p){
	for(auto &i:p){
		cout << i << " ";
	}
	cout << endl;
}

int main(){
	vector<int> vec = {3, 2, 1, 4, 55, 32};
	vector<int> vec1 = {2, 4, 1, 2, 2, 5};

	Insert_sort(vec);
	print(vec);
	Insert_sort(vec1);
	print(vec1);

}
