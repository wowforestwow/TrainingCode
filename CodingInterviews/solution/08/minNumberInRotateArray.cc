#include <bits/stdc++.h>

using namespace std;


class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0 )
            return 0;
        if(rotateArray.size() == 1)
            return rotateArray[0];
        int position = rotateArray.size();
        /*int pivot = rotateArray[0];*/
        //int left = 0;
        //int right = rotateArray.size();

        while(position != 0) {
            int pivot = rotateArray[0];
            int left = 0;
            int right = position;
            while(true) {
                while(rotateArray[++left] < pivot);
                while(rotateArray[--right] > pivot);
                if(left < right)
                    std::swap(rotateArray[left], rotateArray[right]);
                else
                    break;
            }
            std::swap(rotateArray[0],rotateArray[right]);
            position = right;
        }
        return rotateArray[0];
    }
};


int main() {
    Solution s;
    vector<int> v1 = {3, 4, 5, 1, 2};
    vector<int> v2 = {1, 1, 2, 2, 3};

    cout << s.minNumberInRotateArray(v1) << endl;
    cout << s.minNumberInRotateArray(v2) << endl;
}
