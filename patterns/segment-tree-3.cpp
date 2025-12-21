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
        return l < s.r && s.l < r;
    }
    bool covered_by(segment s) {
        return s.l <= l && r <= s.r;
    }
};

// probably incorrect
template <int h>
struct segment_tree {
    constexpr static int w = 1 << h;
    array<int, w> &data;
    array<int, 2 * w> push;
    array<int, 2 * w> least;
    segment_tree<h>(array<int, w> &data) : data(data) {
        build({1, 0, w});
        fill(push.begin(), push.end(), 0);
    }
    int build(tree_segment s) {
        return least[s.v] =
                   s.dot()
                       ? data[s.l]
                       : min(build(s.ls()), build(s.rs()));
    }
    int get_least(segment q, tree_segment s = {1, 0, w}) {
        if (!s.intersects(q)) {
            return INT32_MAX;
        }
        send_push(s);
        return s.covered_by(q)
                   ? least[s.v]
                   : min(get_least(q, s.ls()), get_least(q, s.rs()));
    }
    void send_push(tree_segment s) {
        if (push[s.v] != 0) {
            if (s.dot()) {
                data[s.l] += push[s.v];
            } else {
                push[s.ls().v] += push[s.v];
                least[s.ls().v] += push[s.v];
                push[s.rs().v] += push[s.v];
                least[s.rs().v] += push[s.v];
            }
            push[s.v] = 0;
        }
    }
    void add(segment q, int d, tree_segment s = {1, 0, w}) {
        if (!s.intersects(q)) {
            return;
        }
        send_push(s);
        if (s.dot()) {
            least[s.v] += d;
            data[s.l] += d;
            cout << s.v << '[' << s.l << ';' << s.r << ')' << least[s.v] << '\n';
            return;
        }
        if (s.covered_by(q)) {
            push[s.v] += d;
            least[s.v] += d;
            cout << s.v << '[' << s.l << ';' << s.r << ')' << least[s.v] << '\n';
            return;
        }
        add(q, d, s.ls());
        add(q, d, s.rs());
        least[s.v] = min(least[s.ls().v], least[s.rs().v]);
        cout << s.v << '[' << s.l << ';' << s.r << ')' << least[s.v] << '\n';
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
        char cmd;
        int l, r;
        cin >> cmd >> l >> r;
        --l;
        if (cmd == '+') {
            int d;
            cin >> d;
            st.add({l, r}, d);
        } else {
            int ans = st.get_least({l, r});
            cout << ans << '\n';
        }
    }
}
