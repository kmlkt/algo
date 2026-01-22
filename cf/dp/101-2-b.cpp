#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> r;
vector<ll> rps;
vector<ll> b;
vector<ll> bps;
vector<ll> a;

ll solve() {
    int n, m;
    cin >> n;
    r.resize(n);
    rps.resize(n);
    a.resize(0);
    for (ll &ri : r) {
        cin >> ri;
    }
    cin >> m;
    b.resize(m);
    bps.resize(m);
    for (ll &bi : b) {
        cin >> bi;
    }

    partial_sum(r.begin(), r.end(), rps.begin());
    partial_sum(b.begin(), b.end(), bps.begin());
    ll mxr = max((ll)0, *max_element(rps.begin(), rps.end()));
    ll mxb = max((ll)0, *max_element(bps.begin(), bps.end()));
    return mxr + mxb;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
