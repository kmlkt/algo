#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
array<array<ll, 3001>, 3001> dp;
array<ll, 3001> x;
array<ll, 3001> c;

void solve() {
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int i = 0; i < n; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= l; ++j) {
            dp[i][j] = INT32_MAX;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = x[i]; j <= l; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j - x[i]] + c[i]);
        }
        for (int j = 0; j <= l - x[i]; ++j) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j + x[i]] + c[i]);
        }
    }
    ll ans = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dp[i][l]);
    }
    if (ans == INT32_MAX) {
        ans = -1;
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
