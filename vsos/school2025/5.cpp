#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
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
    vector<ll> ps(n + 1);
    partial_sum(a.begin(), a.end(), ps.begin() + 1);
    vector<ll> ost(n + 1);
    for (int i = 0; i <= n; ++i) {
        ost[i] = ps[i] % n;
    }
    vector<int> indexof(n, -1);
    int l = -1, r = -1;
    for (int i = 0; i <= n; ++i) {
        int oi = ost[i];
        if (indexof[oi] == -1) {
            indexof[oi] = i;
        } else {
            l = indexof[oi];
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << -1;
    } else {
        cout << l + 1 << ' ' << r;
    }
}
