#include <cstdint>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans = 0;
    for (int i = a; i < b;) {
        if ((i + 2) % c == 0) {
            ++i;
        } else {
            i += 2;
        }
        ++ans;
    }
    cout << ans;
}
