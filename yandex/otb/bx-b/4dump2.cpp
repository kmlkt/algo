#include <algorithm>
#include <array>
#include <cstdint>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1e9;

const int H = 301;
const int L = 301 * 301;
array<array<int, L>, H> dp;

int main() {
    for (auto &row : dp) {
        row.fill(-1);
    }
    dp[0][0] = 0;
    int n, a, b;
    cin >> n >> a >> b;
    int maxL = 0;
    int maxH = 0;
    int ans = -1;
    while (n--) {
        int c, t;
        cin >> c >> t;
        for (int i = maxH; i >= 0; --i) {
            for (int j = maxL; j >= 0; --j) {
                int &from = dp[i][j];
                int &to = dp[i + 1][j + c];
                if (from == -1) {
                    continue;
                }
                to = max(to, from + t);
                if (j + c >= a && to >= b) {
                    ans = i + 1;
                    cout << ans;
                    return 0;
                }
                maxH = max(maxH, i + 1);
                maxL = max(maxL, j + c);
            }
        }
    }
    cout << -1;
}
