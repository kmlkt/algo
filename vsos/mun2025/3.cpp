#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    vector<ll> psl(n);
    vector<ll> psr(n);
    partial_sum(a.begin(), a.end(), psl.begin());
    partial_sum(a.rbegin(), a.rend(), psr.rbegin());
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (psl[i] == psr[i]) {
            ans += i;
        }
    }
    cout << ans;
}
