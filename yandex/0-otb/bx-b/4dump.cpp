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

const int L = 1024;
map<pair<int, int>, int> dp;

int main() {
    dp[make_pair(0, 0)] = 0;
    int n, a, b;
    cin >> n >> a >> b;
    /*vector<pair<int, int>> rr(n);
    for (auto &r : rr)
        cin >> r.first >> r.second;
    */
    stack<pair<int, int>> st;
    while (n--) {
        int c, t;
        cin >> c >> t;
        for (auto p : dp) {
            st.push(p.first);
        }
        while (!st.empty()) {
            auto prev_pos = st.top();
            st.pop();
            auto next_pos = make_pair(
                prev_pos.first + c,
                prev_pos.second + t);
            if (dp.find(next_pos) == dp.end()) {
                dp[next_pos] = dp[prev_pos] + 1;
            } else {
                dp[next_pos] = min(dp[next_pos], dp[prev_pos] + 1);
            }
        }
    }
    int ans = MAX;
    for (auto p : dp) {
        if (p.first.first >= a && p.first.second >= b) {
            ans = min(ans, p.second);
        }
    }
    if (ans == MAX) {
        ans = -1;
    }
    cout << ans;
}
