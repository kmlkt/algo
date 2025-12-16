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

vector<ll> fib(100);
vector<ll> dp(100);

void solve() {
    ll n;
    cin >> n;
    ll lim = 1 << 20;
    ll ans = 0;
    for (int i = 0; i < lim; ++i) {
        ll res = 1;
        for (int pos = 0; pos < 30; ++pos) {
            if (i & (1 << pos)) {
                res *= fib[pos + 2];
            }
        }
        if (res == n) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < fib.size(); ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    dp[1] = 1;
    for (int j = 1; j < dp.size(); ++j) {
        for (int i = 2; i < fib.size(); ++i) {
            ll f = fib[i];
            if (dp[j] && f * j < dp.size()) {
                dp[f * j] += dp[j];
                if (f * j == 40) {
                    cout << "X";
                }
            }
        }
    }
    for (int j = 1; j < dp.size(); ++j) {
        cout << j << ":" << dp[j] << '\n';
    }
}
