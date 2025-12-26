#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> c >> b >> a;
    ll ans = c + (b - a + 2) / 3;
    cout << ans;
}
