#include <algorithm>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll, ll>> make_sums(int n) {
    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    vector<pair<ll, ll>> sums(n + 1);
    sums[0].second = -1;
    for (int i = 0; i < n; ++i) {
        sums[i + 1].first = sums[i].first + a[i].first;
        sums[i + 1].second = a[i].second;
    }
    return sums;
}

ll take(vector<pair<ll, ll>> &sums, int n) {
    if (n >= sums.size()) {
        return take(sums, sums.size() - 1);
    }
    return sums[n].first;
}

vector<ll> indices(vector<pair<ll, ll>> &sums, int n) {
    vector<ll> ans(n);
    for (int i = 1; i <= n; ++i) {
        ans[i - 1] = sums[i].second;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

void print_indices(vector<ll> indices) {
    for (int i : indices) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ll b, k, x, y;
    cin >> b >> k >> x >> y;
    auto ds = make_sums(x);
    auto ps = make_sums(y);
    ll best = 0;
    ll bestN = 0;
    ll bestM = 0;
    for (int n = 0; n <= k; ++n) {
        ll m = k - n;
        ll cur = (b + take(ds, n)) * (100L + take(ps, m));
        if (cur > best) {
            best = cur;
            bestN = n;
            bestM = m;
        }
    }
    bestN = min(bestN, x);
    bestM = min(bestM, y);
    cout << bestN << ' ' << bestM << '\n';
    print_indices(indices(ds, bestN));
    print_indices(indices(ps, bestM));
}
