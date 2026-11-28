#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<ll> a(n);
    for(ll &ai : a)
        cin >> ai;

    int ans = 0;
    for(int mask = 0; mask < (1 << n); ++mask) {
        ll mn = 1e9, mx = -1e9, sum = 0;
        for(int i = 0; i < n; ++i) {
            if(mask & (1 << i)) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
                sum += a[i];
            }
        }
        if(l <= sum && sum <= r && mx - mn >= x) {
            ++ans;
        }
    }
    cout << ans;
}
