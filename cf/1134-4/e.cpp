#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(ll &ai : a) {
        cin >> ai;
    }

    ll sum = 0;
    ll cur = 0;
    vector<ll> ps(n);
    for(int i = n - 1; i >= 0; --i) {
        a[i] += ps[i];
        sum += a[i];
        ps[i] += a[i];
        if(i >= k + 1) {
            ps[i - k - 1] -= a[i];
        }
        if(i >= 1) {
            ps[i - 1] += ps[i];
        }
    }
    //cout << sum << ' ';
    cout << (sum % 2 ? "Alice\n" : "Bob\n");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
