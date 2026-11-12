#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int x0, y0, r;
    cin >> x0 >> y0 >> r;
    cout << x0 << ' ' << y0 + r << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
