#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    ll a, b, n;
    cin >> n >> a >> b;
    bool ans = 0;
    if(a == 1) {
        ans = (n - 1) % b == 0;
    } else {
        for(ll p = 1; p <= n; p *= a) {
            if((n - p) % b == 0) {
                ans = 1;
                break;
            }
        }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
