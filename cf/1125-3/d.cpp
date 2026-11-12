#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = ((ll)1e18) + ((ll)5e17);

int n;
vector<ll> a;
vector<ll> b;
vector<ll> c;

ll op(int i, ll s) {
    ll &ai = a[i], &bi = b[i], &ci = c[i];
    ll curr = ai + bi + ci;
    if(curr >= s) {
        return 0;
    }
    if(ai == bi && bi == ci) {
        return INF;
    }
    if(ai > bi || ai > ci || bi > ci) {
        return s - curr;
    }
    return (s - curr) + 2 * min({bi - ai + 1, ci - ai + 1, ci - bi + 1});
}

ll op(ll s) {
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ll o = op(i, s);
        if(o == INF || ans == INF || o > (INF - ans)) {
            ans = INF;
        } else {
            ans += o;
        }
    }
    return ans;
}

void solve() {
    ll k;
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    ll l = -INF; // op(l) <= k
    ll r = INF; // op(r) > k
    while(l < r - 1) {
        ll m = l + (r - l) / 2;
        ll o = op(m);
        if(o <= k) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
