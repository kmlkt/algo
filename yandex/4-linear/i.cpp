#include <algorithm>
#include <cinttypes>
#include <cstdint>
#include <deque>
#include <iostream>
#include <numeric>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;

int n, m;
stack<ll> les;
vector<ll> lessL;
vector<ll> lessR;
vector<vector<bool>> table;
vector<vector<int>> white_up;

ll calc_histogram(vector<int> &a) {
    for (int i = 0; i < m; ++i) {
        ll ai = a[i];
        while (!les.empty() && a[les.top()] >= ai) {
            les.pop();
        }
        lessL[i] = les.empty() ? -1 : les.top();
        les.push(i);
    }
    while (!les.empty()) {
        les.pop();
    }
    for (int i = m - 1; i >= 0; --i) {
        ll ai = a[i];
        while (!les.empty() && a[les.top()] >= ai) {
            les.pop();
        }
        lessR[i] = les.empty() ? m : les.top();
        les.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ans = max(ans, (lessR[i] - lessL[i] - 1) * a[i]);
    }
    return ans;
}

void build_histogram() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j]) {
                white_up[i][j] = i == 0 ? 1 : white_up[i - 1][j] + 1;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    lessL.resize(m);
    lessR.resize(m);

    table.resize(n, vector<bool>(m, false));
    white_up.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tij;
            cin >> tij;
            table[i][j] = tij == 0;
        }
    }
    build_histogram();

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, calc_histogram(white_up[i]));
    }

    cout << ans;
}
