#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> parent;
vector<int> cnt;

void add_concrete(int uu, int vv) {
    parent[vv] = uu;
    cnt[vv / 10]++;
}

int add_vertex(int uu, int v) {
    add_concrete(uu, v * 10 + cnt[v]);
    return v * 10 + cnt[v] - 1;
}

void add_parent(int uu, int vv) {
    if (vv == 10) {
        return;
    }
    int new_v = add_vertex(uu, vv / 10);
    add_parent(new_v, parent[vv]);
}

void add_edge(int u, int v) {
    if (v == 1 || cnt[u] == 0) {
        return;
    }
    for (int i = 0; i < cnt[u]; ++i) {
        int vv = add_vertex(u * 10 + i, v);
        for (int j = 0; j < cnt[v] - 2; ++j) {
            add_parent(vv, parent[v * 10 + j]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    parent.resize((n + 2) * 10);
    cnt.resize(n + 1);
    cnt[1] = 1;
    while (m--) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    cout << parent.size();
}
