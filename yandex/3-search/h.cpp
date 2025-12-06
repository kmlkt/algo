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
ll n, k;
vector<ll> s;

ll f(ll t) {
    ll ans = 0;
    for (ll si : s) {
        ans += si / t;
    }
    return ans;
}

bool lInv(ll t) {
    return f(t) >= k;
}

int main() {
    cin >> n >> k;
    s.resize(n);
    for (ll &si : s) {
        cin >> si;
    }

    ll l = 0;
    ll r = 1e12;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (lInv(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
}
