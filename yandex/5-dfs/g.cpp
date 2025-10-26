#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;
set<int> cur_used;
bool ans = false;

void dfs(int v) {
    if (used[v]) {
        if (cur_used.find(v) != cur_used.end()) {
            ans = true;
        }
        return;
    }
    used[v] = true;
    cur_used.insert(v);
    for (int u : g[v]) {
        dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    int c = 0;
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        cur_used.clear();
        dfs(v);
        ++c;
    }
    cout << ans;
}
