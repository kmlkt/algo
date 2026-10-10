#include <algorithm>
#include <cstdint>
#include <float.h>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int s = 0;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        s += ai;
    }
    cout << ((s % 4 == 0) ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
