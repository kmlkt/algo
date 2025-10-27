#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<vector<int>> gu;
vector<bool> used;
vector<bool> rec;
bool cycle = false;
vector<int> topsort;
vector<int> comp;

void dfs(int v) {
    if (used[v]) {
        if (rec[v]) {
            cycle = true;
        }
        return;
    }
    used[v] = true;
    rec[v] = true;
    for (int u : g[v]) {
        dfs(u);
    }
    rec[v] = false;
}

void dfs_comp(int v, int c) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp[v] = c;
    for (int u : gu[v]) {
        dfs_comp(u, c);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    gu.resize(n);
    used.resize(n);
    rec.resize(n);
    comp.resize(n);
    set<pair<int, int>> ee;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        gu[u].push_back(v);
        gu[v].push_back(u);
        ee.insert({u, v});
    }
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        dfs(v);
    }
    fill(used.begin(), used.end(), false);
    int c = 0;
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        dfs_comp(v, c);
        ++c;
    }
    reverse(topsort.begin(), topsort.end());
    if (cycle) {
        cout << -1;
    } else {
        for (int v : topsort) {
            cout << (v + 1) << ' ';
        }
    }
    topsort.resize(n);
    for (auto &v : topsort) {
        cin >> v;
        --v;
    }
    bool ok = !cycle;
    vector<bool> comp_was(c);
    comp_was[comp[topsort[0]]] = true;
    for (int i = 1; i < n; ++i) {
        int u = topsort[i - 1];
        int v = topsort[i];
        if (comp[u] != comp[v] && comp_was[comp[v]]) {
            ok = false;
            break;
        }
        comp_was[comp[v]] = true;
        if (ee.find({u, v}) == ee.end() && comp[u] == comp[v]) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO");
}
