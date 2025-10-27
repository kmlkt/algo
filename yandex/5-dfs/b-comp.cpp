#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;
vector<vector<int>> ans;

void dfs(int v, vector<int> &comp) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    comp.push_back(v);
    for (int u : g[v]) {
        dfs(u, comp);
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
        g[v].push_back(u);
    }
    for (int v = 0; v < n; ++v) {
        if (used[v]) {
            continue;
        }
        ans.push_back(vector<int>());
        dfs(v, ans[ans.size() - 1]);
    }
    cout << ans.size() << '\n';
    for (auto comp : ans) {
        cout << comp.size() << '\n';
        sort(comp.begin(), comp.end());
        for (int v : comp) {
            cout << v + 1 << ' ';
        }
        cout << '\n';
    }
}
