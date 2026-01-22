#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> a;

ll solve() {
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    ll mn = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int ai = a[i];
        ai -= mn;
        ll rest = n - i;
        ll garant = ai * rest;
        if (k <= garant) {
            ans += k;
            break;
        }
        ans += garant + 1;
        k -= garant;
        mn += ai;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
