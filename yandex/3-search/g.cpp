#include <algorithm>
#include <cinttypes>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
ll n, x, y;

ll f(ll t) {
    ll tRest = t - min(x, y);
    if (tRest < 0) {
        return 0;
    }
    return 1 + tRest / x + tRest / y;
}

bool lInv(ll t) {
    return f(t) < n;
}

int main() {
    cin >> n >> x >> y;

    ll l = 0;
    ll r = 1e11;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (lInv(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;
}
