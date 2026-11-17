#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<bool> a(26);
    for(int i = 0; i < n/2; ++i) {
        char q = min(s[i], s[n-i-1]);
        char p = max(s[i], s[n-i-1]);
        for(char c = q + 1; c <= p; ++c) {
            a[c - 'a'] = 1;
        }
    }
    int ans = 0;
    for(bool ai : a) {
        ans += ai;
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
