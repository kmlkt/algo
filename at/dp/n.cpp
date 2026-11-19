#include <algorithm>
#include <array>
#include <cstdint>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1 << 21;
array<int, N> previ;
array<int, N> curr;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    vector<ll> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());
    auto sum = [&](int l, int cnt) {return ps[l + cnt] - (l == 0 ? 0 : ps[l - 1]);};
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int l = 0; l < n; ++l) {
        dp[l][0] = 0;
    }
    for(int s = 1; s < n; ++s) {
        for(int l = 0; l + s < n; ++l) {
            dp[l][s] = INT64_MAX;
            for(int s1 = 0; s1 < s; ++s1) {
                dp[l][s] = min(dp[l][s], dp[l][s1] + dp[l + s1 + 1][s - s1 - 1]);
            }
            dp[l][s] += sum(l, s);
        }
    }
    cout << dp[0][n - 1] << '\n';
}
