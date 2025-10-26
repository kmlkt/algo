#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u][v] = true;
    }
    for (auto v : g) {
        for (int e : v) {
            cout << e << ' ';
        }
        cout << '\n';
    }
}
