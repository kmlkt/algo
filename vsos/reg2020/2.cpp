#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll vert(ll s, ll n, ll m, ll x) {
    ll first = x * (x + 1) / 2;
    ll last = first + (n - 1) * x * m;
    ll sup = n * (first + last) / 2;
    return s - 2 * sup;
}

pair<ll, ll> vert(ll n, ll m) {
    ll s = n * m * (n * m + 1) / 2;
    ll l = 0; // horiz(l) >= 0
    ll r = m; // horiz(r) < 0
    while (l < r - 1) {
        ll c = (l + r) / 2;
        if (vert(s, n, m, c) < 0) {
            r = c;
        } else {
            l = c;
        }
    }
    pair ansl{l, vert(s, n, m, l)};
    pair ansr{r, vert(s, n, m, r)};
    if (abs(ansl.second) < abs(ansr.second)) {
        return ansl;
    } else {
        return ansr;
    }
}

ll horiz(ll s, ll n, ll m, ll x) {
    ll sup = x * m * (x * m + 1) / 2;
    return s - 2 * sup;
}

pair<ll, ll> horiz(ll n, ll m) {
    ll s = n * m * (n * m + 1) / 2;
    ll l = 0; // horiz(l) >= 0
    ll r = n; // horiz(r) < 0
    while (l < r - 1) {
        ll c = (l + r) / 2;
        if (horiz(s, n, m, c) < 0) {
            r = c;
        } else {
            l = c;
        }
    }
    pair ansl{l, horiz(s, n, m, l)};
    pair ansr{r, horiz(s, n, m, r)};
    if (abs(ansl.second) < abs(ansr.second)) {
        return ansl;
    } else {
        return ansr;
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    auto v = vert(n, m);
    auto h = horiz(n, m);
    if (abs(v.second) < abs(h.second)) {
        cout << "V " << v.first + 1;
    } else {
        cout << "H " << h.first + 1;
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
