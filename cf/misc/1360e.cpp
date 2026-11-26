#include <algorithm>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<string> a(n);
    for(string &ai : a) {
        cin >> ai;
    }
    bool ans = 1;
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(a[i][j] == '1' && a[i+1][j] == '0' && a[i][j+1] == '0') {
                ans = 0;
                break;
            }
        }
    }
    cout << (ans ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
