#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int g1, g2, m;
    cin >> g1 >> g2 >> m;
    string s;
    cin >> s;

    int ans = g1 + g2;

    for(int i = 0; i < m; ++i) {
        if(g1 + g2 == 0) {
            break;
        }
        if(s[i] == '+') {
            if(g2 > 0) {
                ++g2;
            } else {
                --g1;
                ++g2;
            }
        } else {
            if(g2 > 1) {
                --g2;
                ++g1;
            } else if(g1 > 0) {
                --g1;
            } else {
                --g2;
                ++g1;
            }
        }
        ans = max(ans, g1 + g2);
    }

    cout << ans << '\n';
    return;

    vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(g1 + m + 1, vector<int>(g2 + m + 1)));
    for(int k1 = 0; k1 <= g1 + m; ++k1) {
        for(int k2 = 0; k2 <= g2 + m; ++k2) {
            dp[m][k1][k2] = k1 + k2;
        }
    }
    for(int i = m - 1; i >= 0; --i) {
        for(int k1 = 0; k1 <= g1 + i; ++k1) {
            for(int k2 = 0; k2 <= g2 + i; ++k2) {
                if(s[i] == '+') {
                    dp[i][k1][k2] = max(k1 > 0 ? dp[i+1][k1 - 1][k2 + 1] : 0, k2 > 0 ? dp[i+1][k1][k2 + 1] : 0);
                } else {
                    dp[i][k1][k2] = max(k1 > 0 ? dp[i+1][k1 - 1][k2] : 0, k2 > 0 ? dp[i+1][k1 + 1][k2 - 1] : 0);
                }
            }
        }
    }

    cout << dp[0][g1][g2] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
