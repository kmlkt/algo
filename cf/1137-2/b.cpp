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
    int n, k;
    cin >> n >> k;
    int d = n - k;
    vector<int> a(n + d);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> o(n + d);
    for(int i = 0; i < n; ++i) {
        o[i+d] = a[i];
    }
    map<int, int> cnt;
    int nonzeros = 0;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i]) {
            if(cnt[a[i]] == 0) {
                ++nonzeros;
            }
            ++cnt[a[i]];
        }
        if(nonzeros == 1 && i >= d) {
            ++ans;
        }
        if(o[i]) {
            --cnt[o[i]];
            if(cnt[o[i]] == 0) {
                --nonzeros;
            }
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
