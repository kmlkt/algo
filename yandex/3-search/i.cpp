#include <algorithm>
#include <cerrno>
#include <cinttypes>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
ll N, A, B, W, H;

ll cnt(ll w, ll h) {
    return max((W / w) * (H / h), (W / h) * (H / w));
}

ll f(ll d) {
    return cnt(A + 2 * d, B + 2 * d);
}

bool lInv(ll d) {
    return f(d) >= N;
}

int main() {
    cin >> N >> A >> B >> W >> H;
    ll l = 0;
    ll r = 1e18;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (lInv(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l;
}
