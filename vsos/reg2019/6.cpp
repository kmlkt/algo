#include <array>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    --k;
    vector<vector<ll>> up(n, vector<ll>(n));
    vector<vector<ll>> down(n, vector<ll>(n));
    up[0][k] = 1;
    down[0][k] = 1;
    vector<ll> psup(n);
    vector<ll> psdown(n);
    for (int d = 1; d < n; ++d) {
        partial_sum(up[d - 1].begin(), up[d - 1].end(), psup.begin());
        partial_sum(down[d - 1].rbegin(), down[d - 1].rend(), psdown.rbegin());
        for (int sum = 1; sum < n; ++sum) {
            up[d][sum] = psdown[sum - 1] % mod;
        }
        for (int sum = 0; sum < n - 1; ++sum) {
            down[d][sum] = psup[sum + 1] % mod;
        }
    }
    ll ans = up[n - 1][n - 1] + down[n - 1][n - 1];
    ans %= mod;
    cout << ans;
}
