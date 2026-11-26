#include <algorithm>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    priority_queue<pair<int, int>> q;
    q.push({n, 0});
    int i = 1;
    while (!q.empty()) {
        auto [len, s] = q.top();
        s = -s;
        q.pop();
        if(len == 0)
            break;
        int m = s + (len - 1) / 2;
        a[m] = i;
        q.push({m - s, -s});
        q.push({s + len - m - 1, -(m + 1)});
        ++i;
    }
    for(int ai : a) {
        cout << ai << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
