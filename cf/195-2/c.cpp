#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &ai : a) {
        cin >> ai;
    }
    vector<ll> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());
    vector<vector<int>> groups(k);
    groups[0].push_back(-1);
    for(int i = 0; i < n; ++i) {
        groups[ps[i] % k].push_back(i);
    }
    ll ans = 0;
    for(int rem = 0; rem < k; ++rem) {
        auto &group = groups[rem];
        for(int i : group) {
            ans += group.end() - upper_bound(group.begin(), group.end(), i + k);
        }
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
