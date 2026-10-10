#include <algorithm>
#include <cstdint>
#include <float.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

map<ll, ll> a;
map<ll, vector<int>> ind;

void solve() {
    int n;
    cin >> n;
    a.clear();
    ind.clear();
    for(int i = 0; i < n; ++i) {
        ll aᵢ;
        cin >> aᵢ;
        ++a[aᵢ];
        ind[aᵢ].push_back(i);
    }
    vector<pair<ll, ll>> p(a.begin(), a.end());
    vector<ll> r(p.size());
    if(p[0].first != 0) {
        cout << "-1\n";
        return;
    }
    ll s = 0;
    for(int i = 0; i < p.size() - 1; ++i) {
        ll diff = p[i + 1].first - s;
        if(diff % p[i].second != 0) {
            cout << "-1\n";
            return;
        }
        r[i] = diff / p[i].second;
        if(i != 0 && r[i] <= r[i - 1]) {
            cout << "-1\n";
            return;
        }
        s += diff;
    }
    if(p.size() == 1) {
        r[0] = 1;
    } else {
        r[p.size() - 1] = r[p.size() - 2] + 1;
    }
    vector<ll> ans(n);
    for(int i = 0; i < p.size(); ++i) {
        for(int j : ind[p[i].first]) {
            ans[j] = r[i];
        }
    }
    for(ll ai : ans) {
        cout << ai << ' ';
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
