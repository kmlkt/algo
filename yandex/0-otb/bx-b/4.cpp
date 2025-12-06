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
array<map<int, int>, H> dp;

int main() {
    dp[0][0] = 0;
    int n, a, b;
    cin >> n >> a >> b;
    /*vector<pair<int, int>> zz(n);
    for (auto &z : zz) {
        cin >> z.first >> z.second;
        }*/
    int maxH = 0;
    int ans = MAX;
    while (n--) {
        int c, t;
        cin >> c >> t;
        for (int h = maxH; h >= 0; --h) {
            bool found = false;
            for (auto p : dp[h]) {
                int &to = dp[h + 1][p.first + c];
                to = max(to, p.second + t);
                if (p.first + c >= a && to >= b) {
                    ans = min(ans, h + 1);
                    found = true;
                    break;
                }
                maxH = max(maxH, h + 1);
            }
            if (found) {
                break;
            }
        }
    }
    if (ans == MAX) {
        ans = -1;
    }
    cout << ans;
}
