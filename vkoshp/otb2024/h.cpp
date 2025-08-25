#include <iostream>
#include <vector>
using namespace std;

const int COLORS = 100000;
int ans = 0;

struct color {
    vector<int> vertices;
    int sum;
    int perfect_vertices;

    void add(int u, int v) {
        ignore_me();
        add(u);
        add(v);
        notice_me();
    }
    void rem(int u, int v) {
        ignore_me();
        rem(u);
        rem(v);
        notice_me();
    }
    void ignore_me() {
        if (perfect_vertices == vertices.size()) {
            ans -= sum;
        }
    }
    void notice_me() {
        if (perfect_vertices == vertices.size()) {
            ans += sum;
        }
    }
    void add(int u) {
        ignore(u);
        ++vertices[u];
        notice(u);
    }
    void rem(int u) {
        ignore(u);
        --vertices[u];
        notice(u);
    }
    void ignore(int u) {
        sum -= vertices[u];
        if (vertices[u] <= 1) {
            --perfect_vertices;
        }
    }
    void notice(int u) {
        sum += vertices[u];
        if (vertices[u] <= 1) {
            ++perfect_vertices;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<color> colors(COLORS, color{vector<int>(n), 0, n});
    for (int i = 0; i < q; ++i) {
        char sign;
        int u, v, c;
        cin >> sign >> u >> v >> c;
        --u;
        --v;
        --c;
        if (sign == '+') {
            colors[c].add(u, v);
        }
        if (sign == '-') {
            colors[c].rem(u, v);
        }
        cout << ans / 2 << endl;
    }
}
