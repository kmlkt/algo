#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;

struct dfs_ans {
    int v;
    int dist;
};

dfs_ans dfs(int v) {
    if (used[v]) {
        return {v, 0};
    }
    used[v] = true;
    dfs_ans ans = {v, 0};
    for (int u : g[v]) {
        auto ansu = dfs(u);
        if (ansu.dist > ans.dist) {
            ans = ansu;
        }
    }
    ++ans.dist;
    return ans;
}

int main() {
    int n;
    cin >> n;
    g.resize(n);
    used.resize(n);
    int m = n - 1;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto u = dfs(0);
    fill(used.begin(), used.end(), 0);
    auto ans = dfs(u.v);
    cout << ans.dist;
}
