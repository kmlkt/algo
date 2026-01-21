#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    array<vector<ll>, 28> ps;
    ps.fill(vector<ll>(n + 1));
    for (int i = 0; i < n; ++i) {
        ++ps[s[i] - 'a'][i + 1];
    }
    for (auto &psi : ps) {
        partial_sum(psi.begin(), psi.end(), psi.begin());
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        ll ans = 0;
        for (int i = 0; i < 28; ++i) {
            auto &psi = ps[i];
            ans += (psi[r] - psi[l]) * (i + 1);
        }
        cout << ans << '\n';
    }
}
