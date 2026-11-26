#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        ++cnt[ai - i];
    }
    ll ans = 0;
    for(auto [_, c] : cnt) {
        ans += 1LL * c * (c - 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
