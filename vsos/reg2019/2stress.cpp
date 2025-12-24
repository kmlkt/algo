#include <cmath>
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
    ll x2 = k;
    for (ll i = 1; i <= 100500; i += 2) {
        x2 += i;
        ll rt = sqrt(x2);
        if (rt * rt == x2) {
            x = rt;
            break;
        }
    }
    if (x == INT64_MAX) {
        cout << "none";
    } else {
        cout << x;
    }
}
