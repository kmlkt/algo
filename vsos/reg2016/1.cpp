#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, k, x, y;
    cin >> n >> k >> y >> x;
    ll group = (k - 1) * x + y;
    ll grouped = n / k;
    ll rest = n % k;
    ll podjezd = group * grouped + x * rest;
    int q;
    cin >> q;
    while (q--) {
        ll a;
        cin >> a;
        --a;
        ll b = a % podjezd;
        ll g = b / group;
        ll ing = b % group;
        ll ans = g * k + (ing) / x;
        ++ans;
        cout << ans << '\n';
    }
}
