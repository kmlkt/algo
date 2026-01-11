#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int n, m;
vector<vector<int>> g;
vector<vector<int>> nobridge;
vector<int> h;
vector<int> hup;
vector<bool> used;
vector<int> comp;
vector<int> compsz;
vector<set<int>> compg;

void dfs_bridges(int v, int p) {
    if (used[v]) {
        return;
    }
    hup[v] = h[v];
    used[v] = true;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        } else if (used[to]) {
            hup[v] = min(hup[v], h[to]);
        } else {
            h[to] = h[v] + 1;
            dfs_bridges(to, v);
            hup[v] = min(hup[v], hup[to]);
        }
        if (hup[to] > h[v]) {
            // bridge
        } else {
            nobridge[v].push_back(to);
        }
    }
}
void dfs_comp(int v, int c) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp[v] = c;
    for (int to : nobridge[v]) {
        dfs_comp(to, c);
    }
}
void dfs_compg(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    for (int to : g[v]) {
        if (comp[to] != comp[v]) {
            compg[v].insert(comp[to]);
        }
        dfs_compg(to);
    }
}

ll mod = 1e9 + 7;

int main() {
    cin >> n >> m;
    g.resize(n);
    h.resize(n);
    hup.resize(n);
    used.resize(n);
    nobridge.resize(n);
    comp.resize(n);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs_bridges(0, -1);
    fill(used.begin(), used.end(), false);
    int c = 0;
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        dfs_comp(v, c);
        ++c;
    }
    compsz.resize(c);
    compg.resize(c);
    for (int v = 0; v < n; ++v) {
        ++compsz[comp[v]];
    }
    fill(used.begin(), used.end(), false);
    dfs_compg(0);
    ll cnt = 0;
    ll ways = 1;
    for (int cc = 0; cc < c; ++cc) {
        if (compg[cc].size() == 1) {
            ++cnt;
            ways *= compsz[cc];
            ways %= mod;
        }
    }
    cout << cnt << ' ' << ways;
}
