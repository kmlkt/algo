#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

struct range {
    int l, r;
};

struct oper : range {
    ll d;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (ll &ai : a) {
        cin >> ai;
    }
    vector<oper> o(m);
    for (oper &oi : o) {
        cin >> oi.l >> oi.r >> oi.d;
        --oi.l;
    }
    vector<ll> operD(m);
    for (int j = 0; j < k; ++j) {
        int x, y;
        cin >> x >> y;
        --x;
        ++operD[x];
        if (y != m) {
            --operD[y];
        }
    }
    vector<ll> operCnt(m);
    partial_sum(operD.begin(), operD.end(), operCnt.begin());
    vector<ll> aD(n);
    for (int i = 0; i < m; ++i) {
        oper &oi = o[i];
        ll cnt = operCnt[i];
        aD[oi.l] += oi.d * cnt;
        if (oi.r != n) {
            aD[oi.r] -= oi.d * cnt;
        }
    }
    vector<ll> ans(n);
    partial_sum(aD.begin(), aD.end(), ans.begin());
    for (int i = 0; i < n; ++i) {
        ans[i] += a[i];
    }
    for (auto &ansi : ans) {
        cout << ansi << ' ';
    }
}
