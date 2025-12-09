#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct interval {
    ll l, r;
    const ll size() const {
        if (r < l) {
            return 0;
        }
        return r - l;
    }
    const bool empty() const {
        return size() == 0;
    }
    const interval operator*(const interval &other) const {
        return {max(l, other.l), min(r, other.r)};
    }
    const bool operator==(const interval &other) const {
        return l == other.l && r == other.r;
    }
    const interval translate(int delta) const {
        return {l + delta, r + delta};
    }
    const interval next() const {
        return translate(size());
    }
    const interval resize(int size) const {
        return {l, l + size};
    }
    const interval add(int deltaSize) const {
        return {l, r + deltaSize};
    }
    const interval half() const {
        return resize(size() / 2);
    }
    const bool covers(interval other) const {
        return (*this * other) == other;
    }
};

struct rectangle {
    interval x, y;
    const ll size() const {
        return x.size() * y.size();
    }
    const bool empty() const {
        return size() == 0;
    }
    const rectangle operator*(const rectangle &other) const {
        return {x * other.x, y * other.y};
    }
    const bool operator==(const rectangle &other) const {
        return x == other.x && y == other.y;
    }
    const bool covers(const rectangle &other) const {
        return x.covers(other.x) && y.covers(other.y);
    }
};
struct binrect : rectangle {
    bool black;
    const binrect next_top() const {
        binrect ans;
        ans.x = x.next().half();
        ans.y = y.half();
        ans.black = !black;
        return ans;
    }
    const binrect next_bottom() const {
        binrect ans;
        ans.x = x.next().half();
        ans.y = y.half().next();
        ans.black = black;
        return ans;
    }
    const rectangle next_all() const {
        return rectangle{x.next().add(-1), y};
    }
    const ll black_inside(const rectangle &q) const {
        if (q.x.r <= x.l || (y * q.y).empty()) {
            return 0;
        }
        ll ans = (q * (*this)).size() * black;
        if (q.y.covers(y)) {
            ans += (q * next_all()).size() / 2;
        } else {
            ans += next_top().black_inside(q);
            ans += next_bottom().black_inside(q);
        }
        return ans;
    }
};

int main() {
    ll n;
    int q;
    cin >> n >> q;
    ll p2n = 1;
    p2n <<= n;
    binrect first;
    first.x = {0, p2n / 2};
    first.y = {0, p2n};
    first.black = true;
    while (q--) {
        ll y, x, h, w;
        cin >> y >> x >> h >> w;
        --y;
        --x;
        rectangle qr{{x, x + w}, {y, y + h}};
        cout << first.black_inside(qr) << "\n";
    }
}
