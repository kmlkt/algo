#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> sz(61);

ll st(ll top, ll l, ll r) {
    ll child_w = (((ll)1) << top) - 1;
    ll my_w = 2 * child_w + 1;
    if (l <= 1 && my_w <= r) {
        return sz[top];
    }
    if (r < 1 || my_w < l) {
        return 0;
    }
    ll ans = st(top - 1, l, r) + st(top - 1, l - child_w - 1, r - child_w - 1);
    if (l <= child_w + 1 && child_w + 1 <= r) {
        ans += top;
    }
    return ans;
}

int main() {
    for (int i = 1; i <= 60; ++i) {
        sz[i] = i + 2 * sz[i - 1];
    }
    ll l, r;
    cin >> l >> r;
    cout << st(60, l, r);
}
