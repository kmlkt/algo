#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> lamps(n);
    vector<int> x(n);
    for (auto &ai : a) {
        cin >> ai;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        ++lamps[l];
        if (r < n) {
            --lamps[r];
        }
    }
    partial_sum(lamps.begin(), lamps.end(), lamps.begin());
    for (int i = 0; i < n; ++i) {
        if (lamps[i] == 0) {
            x[i] = INT32_MAX;
        } else {
            x[i] = (a[i] - 1) / lamps[i] + 1;
        }
    }
    sort(x.begin(), x.end());
    int ans = x[k - 1];
    if (ans == INT32_MAX) {
        ans = -1;
    }
    cout << ans;
}
