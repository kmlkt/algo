#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll dp[61][61][61];
    dp[0][0][0] = n;

    for (int x = 0; x <= a; ++x) {
        for (int y = 0; y <= b; ++y) {
            for (int z = 0; z <= c; ++z) {
                ll &cur = dp[x][y][z];
                if (x > 0 || y > 0 || z > 0) {
                    cur = INT64_MAX;
                }
                if (x > 0) {
                    cur = min(cur, dp[x - 1][y][z] / 2);
                }
                if (y > 0) {
                    cur = min(cur, (dp[x][y - 1][z] + 1) / 2);
                }
                if (z > 0) {
                    cur = min(cur, max((ll)0, dp[x][y][z - 1] - 1) / 2);
                }
            }
        }
    }
    cout << dp[a][b][c];
}
