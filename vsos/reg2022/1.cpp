#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll mindiv(ll k) {
    return k;
}

pair<ll, ll> solve(ll a, ll b, ll k, ll m) {
    for (ll x = 1; x * x <= m; ++x) {
        if (m % x == 0) {
            ll y = m / x;
            if (x + y == k + 2) {
                if (x <= a && y <= b) {
                    return {x - 1, y - 1};
                }
            }
        }
    }
    {
        ll x = m;
        ll y = m / x;
        if (x + y == k + 2) {
            if (x <= a && y <= b) {
                return {x - 1, y - 1};
            }
        }
    }
    return {-1, -1};
}

void solve() {
    ll a, b, k, m;
    cin >> a >> b >> k >> m;
    pair<ll, ll> ans;
    if (a <= b) {
        ans = solve(a, b, k, m);
    } else {
        ans = solve(b, a, k, m);
        swap(ans.first, ans.second);
    }
    if (ans.first == -1) {
        cout << -1;
    } else {
        cout << ans.first << ' ' << ans.second;
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
