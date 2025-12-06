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
ll N, A, B;

bool lInv(ll d) {
    if (d < B || d < A) {
        return true;
    }
    return (d / A) * (d / B) < N;
}

int main() {
    cin >> A >> B >> N;
    ll l = 0;
    ll r = max(A, B) * N;
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
