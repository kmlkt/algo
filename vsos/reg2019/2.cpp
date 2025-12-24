#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll k;
    cin >> k;
    if (k == 0) {
        cout << 0;
        return 0;
    }
    ll x = INT64_MAX;
    for (ll a = 1; a * a <= abs(k); ++a) {
        if (k % a != 0) {
            continue;
        }
        ll b = k / a;
        ll s = abs(a + b);
        if (s % 2 != 0) {
            continue;
        }
        x = min(x, s / 2);
    }
    if (x == INT64_MAX) {
        cout << "none";
    } else {
        cout << x;
    }
}
