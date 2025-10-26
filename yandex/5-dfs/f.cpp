#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> used;
int ans = 0;

void dfs(int v) {
    if (used[v]) {
        return;
    }
    used[v] = true;
    ++ans;
    for (int u : g[v]) {
        dfs(u);
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    s--;
    g.resize(n);
    used.resize(n);
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            int e;
            cin >> e;
            if (e) {
                g[u].push_back(v);
            }
        }
    }
    dfs(s);
    cout << ans;
}
