#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll m = 998244353;

int main() {
    ll a, b, r, n;
    cin >> a >> b >> r >> n;
    vector<ll> p(n + 1);
    for (ll i = 1; i <= n; ++i) {
        p[i] = (a + b * p[i - 1]) % r;
    }
    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            if (abs(p[i] - p[j]) == 2) {
                ++ans;
            }
        }
    }
    cout << ans;
}
