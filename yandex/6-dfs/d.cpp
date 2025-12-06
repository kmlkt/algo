#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
template <class T>
using table = vector<set<T>>;

table<int> g;
vector<bool> root;
int comp = 0;
vector<bool> used;
table<int> rgc;
vector<pair<int, int>> edges;
vector<bool> edgerev;
vector<int> h;
vector<int> hup;
bool bridge = false;
set<int> vis_children;

void dfs_bridges(int u, int p) {
    used[u] = true;
    hup[u] = h[u];
    for (int e : g[u]) {
        auto &edge = edges[e];
        int v = edge.first;
        if (v == u) {
            v = edge.second;
        }
        if (e == p) {
            continue;
        } else {
            if (!edgerev[e]) {
                edge.first = u;
                edge.second = v;
                edgerev[e] = true;
            }
            if (used[v]) {
                hup[u] = min(hup[u], h[v]);
            } else {
                h[v] = h[u] + 1;
                dfs_bridges(v, e);
                hup[u] = min(hup[u], hup[v]);
                if (hup[v] > h[u]) {
                    // bridge = true;
                }
            }
        }
    }
}

void dfs_check1(int u) {
    used[u] = true;
    for (int e : g[u]) {
        auto &edge = edges[e];
        if (edge.first != u) {
            continue;
        }
        int v = edge.second;
        if (!used[v]) {
            dfs_check1(v);
        }
    }
}

void dfs_check2(int u) {
    used[u] = true;
    for (int e : g[u]) {
        auto &edge = edges[e];
        if (edge.second != u) {
            continue;
        }
        int v = edge.first;
        if (!used[v]) {
            dfs_check2(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    h.resize(n);
    hup.resize(n);
    used.resize(n);
    edges.resize(m);
    edgerev.resize(m);
    for (int e = 0; e < m; ++e) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (u == v) {
            continue;
        }
        g[u].insert(e);
        g[v].insert(e);
        edges[e] = {u, v};
    }
    dfs_bridges(0, 0);
    fill(used.begin(), used.end(), 0);
    dfs_check1(0);
    for (int u = 0; u < n; ++u) {
        if (!used[u]) {
            bridge = true;
            break;
        }
    }
    fill(used.begin(), used.end(), 0);
    dfs_check2(0);
    for (int u = 0; u < n; ++u) {
        if (!used[u]) {
            bridge = true;
            break;
        }
    }
    if (bridge) {
        cout << 0;
        return 0;
    }
    for (int e = 0; e < m; ++e) {
        auto edge = edges[e];
        if (edgerev[e]) {
            // swap(edge.first, edge.second);
        }
        cout << edge.first + 1
             << " " << edge.second + 1
             << "\n";
    }
}
