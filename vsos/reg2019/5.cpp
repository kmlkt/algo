#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    if (c % 2 == 0) {
        if (a % 2 == 0) {
            ans = 1 + (b - a) / 2;
        } else {
            ans = (b - a + 1) / 2;
        }
    } else {
        ll ones = (b - a) / c;
        if ((a % c) % 2 == 0) {
            --ones;
        }
        if ((b % c) % 2 == 0) {
            ++ones;
        }
        ones = abs(ones);
        ans = ones + (b - a - ones + 1) / 2;
    }
    cout << ans;
}
