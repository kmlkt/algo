#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <array>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<int> s(n);
    vector<int> t(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }
    array<ll, 101> mx;
    array<ll, 101> mx_ex;
    array<ll, 101> mx_in;
    mx.fill(-1);
    mx[100] = 0;
    for(int i = 0; i < n; ++i) {
        mx_ex = mx;
        mx_in = mx;
        for(int j = s[i]; j <= 100; ++j) {
            if(mx_ex[j] != -1) {
                mx_ex[j - s[i]] = max(mx_ex[j - s[i]], mx_ex[j] + t[i]);
            }
        }
        for(int j = 100 + p; j >= p; --j) {
            ll &curr = j > 100 ? mx_in[100] : mx_in[j];
            if(mx_in[j - p] != -1) {
                curr = max(curr, mx_in[j - p]);
            }
        }
        for(int j = 0; j <= 100; ++j) {
            mx[j] = max(mx_ex[j], mx_in[j]);
        }
        mx[0] = -1;
    }
    ll ans = *max_element(mx.begin(), mx.end());
    cout << ans;
}
