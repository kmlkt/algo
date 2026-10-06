#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll prevT = 0;
    ll prevS = 0;
    ll straf = 0;
    ll f = 0;
    for (int i = 0; i < n; ++i) {
        ll t, s;
        cin >> t >> s;
        ll d = s - prevS;
        bool success = d > 0;
        if (success) {
            straf += d * t / 100 + 60 * f;
            f = 0;
        } else {
            f++;
        }
        prevT = t;
        prevS = s;
    }
    cout << prevS << ' ' << straf;
}
