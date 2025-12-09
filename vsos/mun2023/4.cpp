#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int ans;

map<int, int> dividers(int x) {
    map<int, int> ans;

    int d = 2;
    while (x % d == 0) {
        ++ans[d];
        x /= d;
    }
    ++d;
    while (d * d <= x) {
        while (x % d == 0) {
            ++ans[d];
            x /= d;
        }
        d += 2;
    }
    if (x != 1) {
        ++ans[x];
    }
    return ans;
}

void double_all(map<int, int> &m) {
    for (auto &[k, v] : m) {
        v *= 2;
    }
}

void permutations(vector<int> &lim,
                  vector<int> &d,
                  function<void(ll)> handle,
                  ll val = 1, int i = 0) {
    if (i == lim.size()) {
        handle(val);
        return;
    }
    ll cur = 1;
    for (int x = 0; x <= lim[i]; ++x) {
        permutations(lim, d, handle, val * cur, i + 1);
        cur *= d[i];
    }
}

bool triangle(ll a, ll b, ll c) {
    return a > 0 && b > 0 && c > 0 && a + b > c && a + c > b && b + c > a;
}

ll stupid_calc(ll x) {
    ll x2 = x * x;
    ll ans = 0;
    for (ll b = 1; b < x2; ++b) {
        ll a2 = x2 + b * b;
        ll a = sqrt(a2);
        if (a * a == a2) {
            ++ans;
        }
    }
    return ans;
}

void solve() {
    ll x;
    cin >> x;
    auto d_map = dividers(x);
    ll x2 = x * x;
    double_all(d_map);
    vector<int> d(d_map.size());
    vector<int> lim(d.size());
    int i = 0;
    for (auto &[k, v] : d_map) {
        d[i] = k;
        lim[i] = v;
        ++i;
    }
    ll ans = 0;
    permutations(lim, d, [x, x2, &ans](ll t) {
        ll a2 = x2 / t + t;
        if (a2 % 2) {
            return;
        }
        ll a = a2 / 2;
        ll b = t - a;
        if (triangle(a, b, x)) {
            ++ans;
        }
    });

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
