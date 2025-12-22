#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i * i * i <= n; ++i) {
        if (n % (i * i) == 0 && n % (i * i * i) != 0) {
            ++ans;
        }
        if (n % i == 0) {
            ll k2 = n / i;
            ll k = sqrt(k2);
            if (k * k == k2) {
                if (n % (k * k * k) != 0) {
                    ++ans;
                }
            }
        }
    }
    cout << ans;
}
