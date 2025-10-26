#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;
vector<int> comp;

void dfs(int v, int c) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp[v] = c;
    for (int u : g[v]) {
        dfs(u, c);
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    t--;
    g.resize(n);
    used.resize(n);
    comp.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u == t || v == t) {
            continue;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int c = 0;
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        dfs(v, c);
        ++c;
    }
    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << (comp[u] == comp[v] ? "Yes" : "No") << '\n';
    }
}
