#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
    }

    vector<int> o(n);
    for(int i = 0; i < n; ++i) {
        o[i] = a[i] - i;
    }

    vector<int> r(n, -1);
    for(int i = 0; i < n; ++i) {
        int p = n + o[i] - 1;
        if(0 <= p && p < n && r[p] == -1) {
            r[p] = i;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << r[i] + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
