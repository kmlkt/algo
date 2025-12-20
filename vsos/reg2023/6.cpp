#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll n, m;
vector<int> a;
vector<int> t;

const ll MAX = 2e9 + 40;

ll pow(ll x, int p) {
    if (p == 0) {
        return 1;
    } else if (p % 2 == 0) {
        ll h = pow(x, p / 2);
        if (h > MAX) {
            return MAX;
        }
        return h * h;
    } else {
        ll e = pow(x, p - 1);
        if (e > MAX) {
            return MAX;
        }
        return x * e;
    }
}

ll sz(int s) {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int ai = a[i];
        int ti = t[i];
        int d = s - ai;
        if (d < 0) {
            continue;
        } else if (d < ti) {
            ++ans;
        } else {
            ans += pow(2, d - ti + 1);
        }
        if (ans > MAX) {
            break;
        }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    t.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    for (int &ti : t) {
        cin >> ti;
    }
    ll l = 0;   // sz(l) < m
    ll r = MAX; // sz(r) >= m
    while (l < r - 1) {
        ll c = (l + r) / 2;
        if (sz(c) < m) {
            l = c;
        } else {
            r = c;
        }
    }
    ll szr = sz(r);
    if (szr == m) {
        cout << r;
    } else {
        cout << -1;
    }
}
