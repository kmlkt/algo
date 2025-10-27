#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> used;
vector<bool> rec;
bool cycle = false;
vector<int> topsort;

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
    topsort.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    rec.resize(n);
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
        dfs(v);
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
}
