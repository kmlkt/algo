#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;
template <class T>
using table = vector<vector<T>>;

table<int> g;
table<int> rg;
vector<int> strong_comp;
vector<bool> root;
int comp = 0;
vector<bool> used;
vector<int> topsort;
table<int> rgc;

void dfs_topsort(int u) {
    used[u] = true;
    for (int v : g[u]) {
        if (!used[v]) {
            dfs_topsort(v);
        }
    }
    topsort.push_back(u);
}

void dfs_strong_comp(int u) {
    strong_comp[u] = comp;
    for (int v : rg[u]) {
        if (strong_comp[v] == -1) {
            dfs_strong_comp(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    rg.resize(n);
    strong_comp.resize(n, -1);
    used.resize(n);
    for (int e = 0; e < m; ++e) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }
    topsort.reserve(n);
    for (int u = 0; u < n; ++u) {
        if (!used[u]) {
            dfs_topsort(u);
        }
    }
    reverse(topsort.begin(), topsort.end());
    for (int u : topsort) {
        if (strong_comp[u] == -1) {
            dfs_strong_comp(u);
            comp++;
        }
    }
    fill(used.begin(), used.end(), false);
    rgc.resize(comp);
    root.resize(comp, true);
    for (int u = 0; u < n; ++u) {
        for (int v : g[u]) {
            if (strong_comp[u] != strong_comp[v]) {
                rgc[strong_comp[v]].push_back(strong_comp[u]);
                root[strong_comp[u]] = false;
            }
        }
    }
    int ans = 0;
    for (int c = 0; c < comp; ++c) {
        if (root[c]) {
            ++ans;
        }
    }
    cout << ans;
}
