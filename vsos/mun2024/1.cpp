#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n, x;
    cin >> n >> x;
    ll m = (n + x - 1) / x;
    ll ans = (m / 3 * 2) + (m % 3);
    cout << ans;
}
