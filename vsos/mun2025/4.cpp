#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> a;
vector<ll> ps;

ll S(int i, int j) {
    if (i == 0) {
        return ps[j];
    }
    return ps[j] - ps[i - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    a.resize(n);
    for (ll &ai : a) {
        cin >> ai;
    }

    ps.resize(n);
    partial_sum(a.begin(), a.end(), ps.begin());
    vector<int> lim(n);
    vector<ll> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        lim[i] = i + 1;
        while (lim[i] < n) {
            ll x = a[lim[i]];
            if (x <= S(i, lim[i] - 1)) {
                lim[i] = lim[lim[i]];
            } else {
                break;
            }
        }
        ans[i] = S(i, lim[i] - 1);
    }
    for (int i = 0; i < n; ++i) {
        cout << S(i, lim[i] - 1) << '\n';
    }
}
