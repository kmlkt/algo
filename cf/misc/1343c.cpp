#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &ai : a) {
        cin >> ai;
    }
    ll ans = 0;
    ll last = a[0];
    for(ll ai : a) {
        if(last * ai < 0) {
            ans += last;
            last = ai;
        }
        last = max(last, ai);
    }
    ans += last;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
