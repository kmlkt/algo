#include <algorithm>
#include <array>
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
    vector<vector<ll>> dp(n, vector<ll>(n));
    for(int l = 0; l < n; ++l) {
        dp[l][0] = a[l];
    }
    for(int s = 1; s < n; ++s) {
        for(int l = 0; l + s < n; ++l) {
            dp[l][s] = max(a[l + s] - dp[l][s - 1], a[l] - dp[l + 1][s - 1]);
        }
    }
    cout << dp[0][n - 1] << '\n';
}
