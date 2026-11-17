#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int col = 'R';
    for(char c : s) {
        if(col != c) {
            ++ans;
            col = c;
        }
        if(col == 'R') {
            col = 'B';
        } else {
            col = 'R';
        }
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
