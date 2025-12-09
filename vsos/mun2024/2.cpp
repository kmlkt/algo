#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    char comma;
    int t, n;
    cin >> t >> n;
    vector<bool> ans(n, 1);
    for (int i = 0; i < t; ++i) {
        int ai;
        cin >> ai;
        if (i != t - 1) {
            cin >> comma;
        }
        ans[ai] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
}
