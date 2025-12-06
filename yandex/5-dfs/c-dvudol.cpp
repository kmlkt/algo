#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> color;

bool dfs(int v, int c) {
    if (color[v]) {
        return color[v] == c;
    }
    color[v] = c;
    for (int u : g[v]) {
        if (!dfs(u, 3 - c)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool ans = true;
    for (int v = 0; v < n; ++v) {
        if (color[v]) {
            continue;
        }
        if (!dfs(v, 1)) {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES" : "NO");
}
