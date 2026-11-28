#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int last_group = 0;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        if(ai) {
            ++last_group;
        } else {
            if(i == last_group) {
                last_group += 2;
            }
            ans += last_group / 3;
            last_group = 0;
        }
    }
    if(n == last_group) {
        last_group += 2;
    }
    ans += last_group / 3;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
