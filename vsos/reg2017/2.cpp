#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    for (int y = 0; y * y * y <= b; ++y) {
        ll y3 = y * y * y;
        if (y3 < a) {
            continue;
        }
        ll l = max(a, (ll)ceil(sqrt(y3 - k)));
        ll r = min(b, (ll)floor(sqrt(y3 + k)));
        ans += (r - l + 1);
    }
    cout << ans;
}
