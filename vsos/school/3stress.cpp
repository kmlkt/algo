#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    for (ll s = 0; s < 100; ++s) {
        int ans = 0;
        for (ll x = 0; x <= s; ++x) {
            // 2x + y = s
            ll y = s - 2 * x;
            if (y < x + x && x < x + y && y != x) {
                ++ans;
            }
        }
        cout << s << ":" << ans << "\n";
    }
}
