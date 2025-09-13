#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

void run() {
    string s;
    ll l, r;
    cin >> s >> l >> r;
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ll x = 0;
        ll px = -1;
        for (int j = i; j < s.size(); ++j) {
            x = x * 10L + (s[j] - '0');
            px = x;
            if (l <= x && x <= r)
                ++ans;
            if (s[i] == '0')
                break;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        run();
    }
}
