#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct motor {
    ll z, a, b;
};

vector<motor> motors;

ll P(ll x, const motor &m) {
    if (x <= m.z) {
        return m.a * x;
    } else {
        return m.z * (m.a - m.b) + m.b * x;
    }
}

ll P(ll x) {
    ll ans = 0;
    for (auto m : motors) {
        ans += P(x, m);
    }
    return ans;
}

int main() {
    int n;
    ll p;
    cin >> n >> p;
    motors.resize(n);
    for (auto &m : motors) {
        cin >> m.z >> m.a >> m.b;
    }
    ll l = 0; // P(l) < p
    ll r = p; // P(r) >= p
    while (l < r - 1) {
        ll m = (l + r) / 2;
        ll pm = P(m);
        if (pm < p) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;
}
