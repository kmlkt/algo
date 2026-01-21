#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int INF = 1e8;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(n + 1);
    dp[0] = 0;
    char s = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2]);
        }
        ++dp[i];
        s = ' ';
        if (dp[i] <= k) {
            s = '1';
        }
        cout << i << '\t' << dp[i] << '\t' << s << '\n';
    }
    cout << '\n';
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
