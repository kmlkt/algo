#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1;
        return 0;
    }
    for (ll diff = -1; diff > -2 * n; diff -= 2) {
        for (ll i = 0; i < n; ++i) {
            ll j = (n * n + i + diff) % n;
            while (j < 0) {
                j += n;
            }
            cout << n - j << ' ';
        }
        cout << '\n';
    }
}
