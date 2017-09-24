#include<iostream>
#include<vector>

using namespace std;

int main()
{
    char ch='a';
    int i= ch;
    cout << i <<endl;
    int count ;
    cin >> count;
    char char_tmp;
    vector<char> vec;
    for(int j=0; j<count; j++)
    {
        cin >> char_tmp;
        vec.push_back(char_tmp);
    }
//	char c;
    for(auto &c:vec)
    {
        cout << "char c: "<< c << endl;
        if(c>='a')
            cout <<"little:"<< c-'a' << endl;
        else
            cout << "big:"<< c-'A' << endl;
    }
    if(true)
    {
    }
    else {
        cout << "hello";
    }
}

