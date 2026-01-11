#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(a % b, b);
}

void solve() {
    ll n, m, h, w;
    cin >> n >> m >> h >> w;
    bool ans = (gcd(h, w) == 1) && n >= 2 * h && m >= 2 * w;
    cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
