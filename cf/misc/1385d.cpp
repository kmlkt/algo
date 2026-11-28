#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto make_good = [&](auto &self, int l, int r, char c) -> int {
        if(l + 1 == r) {
            return s[l] != c;
        }
        int l_diff = 0;
        int r_diff = 0;
        int m = (l + r) / 2;
        for(int i = l; i < m; ++i) {
            if(s[i] != c) {
                ++l_diff;
            }
        }
        for(int i = m; i < r; ++i) {
            if(s[i] != c) {
                ++r_diff;
            }
        }
        int ans = min(l_diff + self(self, m, r, c+1), self(self, l, m, c+1) + r_diff);
        //cerr << s.substr(l, r - l) << ' ' << c << ' ' << ans << '\n';
        return ans;
    };
    cout << make_good(make_good, 0, n, 'a') << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
