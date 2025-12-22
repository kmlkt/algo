#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, m, k;
vector<vector<int>> g;
vector<bool> used;
vector<int> nb;

void dfs(int v) {
    if (used[v] || nb[v] < k) {
        return;
    }
    used[v] = true;
    for (int u : g[v]) {
        ++nb[u];
        dfs(u);
    }
}

int main() {
    cin >> n >> m >> k;
    g.resize(n);
    used.resize(n);
    nb.resize(n);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    int c;
    cin >> c;

    for (int i = 0; i < c; ++i) {
        int v;
        cin >> v;
        --v;
        nb[v] = k;
    }
    for (int v = 0; v < n; ++v) {
        if (nb[v] >= k) {
            dfs(v);
        }
    }
    int ans = 0;
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            ++ans;
        }
    }
    cout << ans;
}
