#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct segment {
    int l, r;
};

struct tree_segment {
    int v, l, r;
    int m() {
        return (l + r) / 2;
    }
    tree_segment ls() {
        return {v * 2, l, m()};
    }
    tree_segment rs() {
        return {v * 2 + 1, m(), r};
    }
    bool dot() {
        return l + 1 == r;
    }
    bool intersects(segment s) {
        return l <= s.l && s.r <= r;
    }
    bool covered_by(segment s) {
        return s.l <= l && r <= s.r;
    }
};

template <int h>
struct segment_tree {
    constexpr static int w = 1 << h;
    array<int, w> &data;
    array<int, 2 * w> least;
    segment_tree<h>(array<int, w> &data) : data(data) {
        build({1, 0, w});
    }
    int build(tree_segment s) {
        return least[s.v] =
                   s.dot()
                       ? data[s.l]
                       : min(build(s.ls()), build(s.rs()));
    }
    int get_least(segment q, tree_segment s = {1, 0, w}) {
        return s.intersects(q)
                   ? (s.covered_by(q)
                          ? least[s.v]
                          : min(get_least(q, s.ls()), get_least(q, s.rs())))
                   : INT32_MAX;
    }
};

int main() {
    // n <= 1e5 => h = 17
    int n;
    cin >> n;
    array<int, 1 << 3> data;
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    segment_tree<3> st(data);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l;
        int ans = st.get_least({l, r});
        cout << ans;
    }
}
