#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll ans = 0;
    for (ll &ai : a) {
        cin >> ai;
        ans += ai;
    }
    int offset = 0;
    int q;
    cin >> q;

    while (q--) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int i, x;
            cin >> i >> x;
            --i;
            i += offset;
            i %= n;
            ans -= a[i];
            ans += x;
            a[i] = x;
        } else {
            int k;
            cin >> k;
            offset -= k;
            if (offset < 0) {
                offset += n;
            }
        }

        cout << ans << '\n';
    }
}
