#include <bits/stdc++.h>

using namespace std;

int count(int m) {
    if (m <= 1)
        return 0;
    if (m == 2)
        return 1;
    if (m == 3)
        return 2;
    return count(m - 1) + count(m - 2);
}

int main() {
    int n;
    cin >> n;
    while (n-- > 0) {
        int m;
        cin >> m;
        int result = count(m);
        cout << result << endl;
    }
    return 0;
}
