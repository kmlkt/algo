#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int DL = 0, DR = 1, INF = 1e6;
struct car {
    int x, p, d, l, r, dp[2];
};

int main() {
    int n;
    cin >> n;
    vector<car> a(n);
    for (car &ai : a) {
        cin >> ai.x >> ai.p >> ai.d;
        if (ai.d == -1) {
            ai.d = 0;
        }
        ai.dp[DL] = ai.dp[DR] = INF;
    }
    for (int i = 1; i < n; ++i) {
        car &c0 = a[i - 1];
        car &c1 = a[i];
        c0.r = c1.l = (c1.x - c0.x);
    }
    {
        car &base = a[0];
        base.dp[DL] = base.d != DL;
        base.dp[DR] = base.d != DR;
    }
    for (int i = 1; i < n; ++i) {
        car &c0 = a[i - 1];
        car &c1 = a[i];
        // L
        if (c1.p >= c1.l) {
            c1.dp[DL] = min(c1.dp[DL], min(c0.dp[DL], c0.dp[DR]) + (c1.d != DL));
        }
        if ((c1.p + c0.p) >= c1.l) {
            c1.dp[DL] = min(c1.dp[DL], c0.dp[DR] + (c1.d != DL));
        }

        // R
        if (c0.p >= c0.r) {
            c1.dp[DR] = c0.dp[DR] + (c1.d != DR);
        }
    }
    car &last = a[n - 1];
    int ans = min(last.dp[DL], last.dp[DR]);
    if (ans == INF) {
        ans = -1;
    }
    cout << ans;
}
