#include <iostream>

using namespace std;
using ll = long long;

ll S(ll n) {
    return n * (1 + n) / 2;
}

int main() {
    ll l, r, a;
    cin >> l >> r >> a;
    ll n = r - l;
    ll ans = (S(n) - ((n / a) * S(a - 1) + S(n % a))) / a;
    cout << ans;
}
