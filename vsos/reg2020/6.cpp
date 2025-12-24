#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

ll num(int len, int d, int pos = -1, int d2 = 0) {
    ll ans = 0;
    for (int i = 0; i < len; ++i) {
        ans *= 10;
        ans += (i == pos) ? d2 : d;
    }
    return ans;
}

int main() {
    ll x;
    cin >> x;
    int k;
    cin >> k;
    ll ans = INT64_MAX;
    if (k == 0) {
        for (int len = 1; len <= 18; ++len) {
            for (int d = 0; d <= 9; ++d) {
                ll y = num(len, d);
                if (y >= x && y < ans) {
                    ans = y;
                }
            }
        }
    } else {
        for (int len = 1; len <= 18; ++len) {
            for (int d = 0; d <= 9; ++d) {
                for (int pos = 0; pos < 18; ++pos) {
                    for (int d2 = 0; d2 <= 9; ++d2) {
                        ll y = num(len, d, pos, d2);
                        if (y >= x && y < ans) {
                            ans = y;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}
