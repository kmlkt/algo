#include <algorithm>
#include <cstdint>
#include <iostream>
#include <list>
#include <vector>

using namespace std;
using ll = long long;

struct rect {
    ll x, y;
    ll profit = 0;
    bool operator<(const rect &other) {
        return x < other.x;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<rect> a(n);
    for (rect &ai : a) {
        cin >> ai.x >> ai.y;
    }
    sort(a.begin(), a.end());

    list<rect *> l;
    for (rect &ai : a) {
        l.push_back(&ai);
    }

    for (auto it = l.cbegin(); it != l.cend();) {
        auto nit = it;
        ++nit;
        if (nit == l.cend()) {
            break;
        }
        auto cur = *it;
        auto next = *nit;
        if (cur->y < next->y) {
            l.erase(it);
        }
        it = nit;
    }

    for (auto it = l.cbegin(); it != l.cend(); ++it) {
        ll px = 0;
        ll ny = 0;
        auto pit = it;
        auto nit = it;
        ++nit;
        --pit;
        if (it != l.cbegin()) {
            px = (*pit)->x;
        }
        if (nit != l.cend()) {
            ny = (*nit)->y;
        }
        auto cur = *it;
        cur->profit = (cur->x - px) * (cur->y - ny);
    }

    sort(a.begin(), a.end(), [](rect l, rect r) { return l.profit > r.profit; });
    vector<rect> t(k);
    for (int i = 0; i < k; ++i) {
        t[i] = a[i];
    }
    sort(t.begin(), t.end());
    ll ans = t[0].x * t[0].y;
    for (int i = 1; i < k; ++i) {
        rect &prev = t[i - 1];
        rect &cur = t[i];
        ans += (cur.x - prev.x) * cur.y;
    }
    cout << ans;
}
