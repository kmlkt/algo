#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll k, x, y;
    cin >> k >> x >> y;
    ll next = y + x - 1;
    ll ans = next - next % x;
    cout << ans;
}
