#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct chair {
    int h, w;
    bool operator<(chair &another) {
        return h < another.h;
    }
};

const int N = 1 << 18;

struct st {
    int zero;
    array<int, 2 * N> v;
    function<int(int, int)> f;
    st(vector<int> &a, int zero, function<int(int, int)> f) : zero(zero), f(f) {
        copy(a.begin(), a.end(), v.begin() + N);
        fill(v.begin() + N + a.size(), v.end(), zero);
        build();
    }
    void build(int l = 0, int r = N, int i = 1) {
        if (l == r - 1) {
            return;
        }
        int m = (l + r) / 2;
        build(l, m, 2 * i);
        build(m, r, 2 * i + 1);
        v[i] = f(v[2 * i], v[2 * i + 1]);
    }
    int get(int ql, int qr, int l = 0, int r = N, int i = 1) {
        if (qr <= l || r <= ql) {
            return zero;
        }
        if (ql <= l && r <= qr) {
            return v[i];
        }
        int m = (l + r) / 2;
        return f(get(ql, qr, l, m, i * 2), get(ql, qr, m, r, i * 2 + 1));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector<chair> a(n);
    for (chair &ai : a) {
        cin >> ai.h;
    }
    for (chair &ai : a) {
        cin >> ai.w;
    }
    sort(a.begin(), a.end());
    vector<int> d(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        d[i] = a[i + 1].h - a[i].h;
    }
    st dst(d, INT32_MIN, [](int l, int r) { return max(l, r); });
    int sum = a[0].w;
    int l = 0;
    int r = 1;
    int ans = INT32_MAX;
    while (r < n) {
        sum += a[r].w;
        ++r;
        if (sum - a[l].w < h) {
            continue;
        }
        while (sum - a[l].w >= h) {
            sum -= a[l].w;
            ++l;
        }
        int anslr = (l == r - 1) ? 0 : dst.get(l, r - 1);
        ans = min(ans, anslr);
    }
    cout << ans;
}
