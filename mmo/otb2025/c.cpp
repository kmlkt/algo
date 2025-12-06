#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> e(n - 1);
    bool eq = true;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        e[i] = w;
        if (i > 0 && e[i] != e[i - 1]) {
            eq = false;
        }
    }
    if (eq) {
        cout << e[0] * (n - 1);
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += e[i];
    }
    vector<ll> dist(n);
    vector<ll> maax(n);
    vector<ll> suum(n);
    vector<ll> ps(n + 1);
    partial_sum(e.begin(), e.end(), ps.begin() + 1);
    for (int i = 0; i < n - 1; ++i) {
        // dist[i] = abs(e[i] - e[i + 1]);
        //  ans += dist[i];
        maax[i] = e[i];
        // suum[i] = e[i] + e[i + 1];
    }
    for (int len = 2; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            maax[i] = max(maax[i], maax[i + 1]);
            suum[i] = ps[i + len] - ps[i];
            dist[i] = max((ll)0, 2 * maax[i] - suum[i]);
            ans += dist[i];
        }
    }
    cout << ans;
}
