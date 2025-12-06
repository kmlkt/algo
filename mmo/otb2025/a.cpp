#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll k = 1; k <= n; ++k) {
        ll top = 2 * n - k * k + k;
        ll bottom = 2 * k;
        if (top < 1) {
            break;
        }
        if (top % bottom == 0) {
            ++ans;
        }
    }
    cout << ans;
}
