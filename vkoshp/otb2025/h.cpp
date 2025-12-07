#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
using ll = long long;
map<int, int> counts;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++counts[ai];
    }
    int ans = -1;
    for (auto p : counts) {
        int ai = p.first;
        int cnt = p.second;
        if (cnt % 2 == 1) {
            ans = ai;
            break;
        }
    }
    counts.clear();
    cout << ans << "\n";
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
