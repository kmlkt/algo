#include <algorithm>
#include <array>
#include <cinttypes>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

ll fac(ll x) {
    if(x <= 1) {
        return 1;
    }
    return (x * fac(x - 1)) % MOD;
}

ll binpow(ll x, ll p) {
    ll ans = 1;
    while (p != 0) {
        if(p & 1) {
            ans = (ans * x) % MOD;
        }
        x = (x * x) % MOD;
        p >>= 1;
    }
    return ans;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll c(ll n, ll k) {
    return ((fac(n) * inv(fac(k)) % MOD) * inv(fac(n - k)) % MOD);
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << c(n + m - 1, m);
}
