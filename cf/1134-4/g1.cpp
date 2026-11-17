#include <algorithm>
#include <array>
#include <bitset>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int n;
ll k;
vector<ll> h;

int next(int i) {
    if(i == n - 1) {
        return 0;
    }
    return i + 1;
}

int prev(int i) {
    if(i == 0) {
        return n - 1;
    }
    return i - 1;
}

ll min_actions(ll crut) {
    vector<ll> h1(h.begin(), h.end());
    for(int i = 0; i < n; ++i) {
        ll dh = abs(h1[next(i) - h1[i]]);
        if(dh > crut) {
            if(h1[next(i)])
        }
    }
}

void solve() {
    cin >> n >> k;
    h.resize(n);
    for(ll &ai : h) {
        cin >> ai;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
