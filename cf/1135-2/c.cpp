#include <algorithm>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

set<vector<int>> s;

void variants(vector<int> &a) {
    s.insert(a);
    auto mx = max_element(a.begin(), a.end());
    if (count(a.begin(), a.end(), *mx) >= 2) {
        return;
    }
    for (int to = 1; to < *mx; ++to) {
        vector<int> t = a;
        t[mx - a.begin()] = to;
        variants(t);
    }
}

const ll MOD = 1e9 + 7;

ll summ(ll a, ll b) {
    return (MOD + a + b) % MOD;
}

ll mulm(ll a, ll b) {
    return (a * b) % MOD;
}

ll powm(ll a, ll p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) {
            res = mulm(res, a);
        }
        a = mulm(a, a);
        p >>= 1;
    }
    return res;
}

void solve() {
    s.clear();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    int first = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == a[i]) {
            first = i + 1;
        }
    }
    vector<int> b(a.begin() + first, a.end());
    if (b.empty()) {
        cout << "1\n";
        return;
    }
    ll res = 0;
    for (int i = 0; i < b.size(); ++i) {
        ll bi = b[i];
        ll ri = mulm(bi, powm(bi - 1, b.size() - i - 1));
        if (i > 0) {
            ri = summ(ri, -powm(b[i - 1] - 1, b.size() - (i - 1) - 1));
        }
        res = summ(res, ri);
    }
    cout << res << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
