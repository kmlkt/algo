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
ll A, K, B, M, X;

ll f(ll d) {
    return A * (d - d / K) + B * (d - d / M);
    // Ad - Ad/K + Bd - Bd / m
    // Ad - A(d-d%k)/k + Bd - B(d-d%m)/m
    // A(d%k/k) + B(d%m/m)
}

bool lInv(ll d) {
    ll fd = f(d);
    if (fd < 0) {
        return false;
    }
    return f(d) < X;
}

int main() {
    cin >> A >> K >> B >> M >> X;
    ll l = -1;
    ll r = X / min(A, B) * 3;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (lInv(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << r;
}
