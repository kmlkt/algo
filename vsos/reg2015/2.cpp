#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll N(ll a, ll b, ll d, ll w, ll h) {
    ll A = a + 2 * d;
    ll B = b + 2 * d;
    return (w / A) * (h / B);
}

ll bs(ll n, ll a, ll b, ll w, ll h) {
    ll l = 0; // N(l) >= n
    ll r = h; // N(R) < n
    while (l < r - 1) {
        ll m = (l + r) / 2;
        if (N(a, b, m, w, h) >= n) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    ll n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    ll d = max(bs(n, a, b, w, h), bs(n, a, b, h, w));
    cout << d;
}
