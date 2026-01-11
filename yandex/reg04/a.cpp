#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

struct gun {
    int i, v;
    bool operator<(gun other) {
        return v < other.v;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<gun> a(n);
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        a[i].i = i;
        cin >> a[i].v;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int mxcnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i].v == a[0].v) {
            ++mxcnt;
        }
    }
    if (mxcnt > k) {
        k = mxcnt;
    }
    int rest = k - mxcnt;
    int mxsum = m - rest;
    int mxtake = mxsum / mxcnt;
    int mxost = mxsum % mxcnt;
    for (int i = 0; i < mxcnt; ++i) {
        ans[a[i].i] = mxtake;
        if (mxost) {
            ++ans[a[i].i];
            --mxost;
        }
    }
    for (int i = mxcnt; i < k; ++i) {
        ans[a[i].i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < ans[i]; ++j) {
            cout << (i + 1) << ' ';
        }
    }
}
