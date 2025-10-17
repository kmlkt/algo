#include <algorithm>
#include <cstdint>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    vector<ll> ps(n);
    partial_sum(a.begin(), a.end(), ps.begin());
    int l = -1;
    ll mn = 0;
    int ansr = 0;
    int ansl = 0;
    ll ans = INT64_MIN;
    for (int r = 0; r < n; ++r) {
        int curans = ps[r] - mn;
        if (curans > ans) {
            ans = curans;
            ansr = r;
            ansl = l;
        }
        if (ps[r] < mn) {
            l = r;
            mn = ps[r];
        }
    }
    cout << ansl + 2 << ' ' << ansr + 1 << ' ' << ans;
}
