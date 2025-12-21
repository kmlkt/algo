#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<int> a;
vector<int> cnt;

int main() {
    cin >> n >> m;
    a.resize(n);
    cnt.resize(m);
    for (int &ai : a) {
        cin >> ai;
        --ai;
        ++cnt[ai];
    }
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1)));
    dp[0][0][cnt[0]] = 1;
    for (int i = 0; i < m; ++i) {
        for (int left_cur = 0; left_cur <= n; ++left_cur) {
            for (int left_prev = 0; left_prev <= n; ++left_prev) {
                dp[1][left_cur][left_prev] = 0;
            }
        }
        for (int left_cur = 0; left_cur <= n; ++left_cur) {
            for (int left_prev = 0; left_prev <= n; ++left_prev) {
                if (left_cur < (m - 3)) {
                    dp[0][left_prev][left_cur] += dp[0][left_prev][left_cur + 3];
                }
                if (i + 1 < m && left_cur >= left_prev && cnt[i + 1] >= left_prev) {
                    dp[1][left_cur - left_prev][cnt[i + 1] - left_prev] += dp[0][left_prev][left_cur];
                }
            }
        }
        swap(dp[0], dp[1]);
    }
    cout << dp[1][0][0];
}
