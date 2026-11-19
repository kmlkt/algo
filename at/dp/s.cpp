#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

int main() {
    string ks;
    int d;
    cin >> ks >> d;
    vector<int> k(ks.size());
    for(int i = 0; i < ks.size(); ++i) {
        k[i] = ks[i] - '0';
    }

    vector<vector<array<int, 2>>> dp(k.size() + 1, vector<array<int, 2>>(d));
    dp[0][0][1] = 1;
    for(int i = 0; i < k.size(); ++i) {
        for(int r = 0; r < d; ++r) {
            for(int tight = 0; tight <= 1; ++tight) {
                for(int c = 0; c <= (tight ? k[i] : 9); ++c) {
                    int &dpnext = dp[i + 1][(r + c) % d][tight && c == k[i]];
                    dpnext = (dpnext + dp[i][r][tight]) % MOD;
                }
            }
        }
    }

    int ans = (dp.back()[0][0] + dp.back()[0][1]) % MOD;
    ans = (ans - 1 + MOD) % MOD;

    cout << ans << '\n';
}
