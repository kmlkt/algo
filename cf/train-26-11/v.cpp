#include <algorithm>
#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
    }
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        ll d = a[i - 1] - a[i];
        if(d > 0) {
            int p2 = 0;
            while((1LL << p2) <= d) {
                ++p2;
            }
            a[i] = a[i - 1];
            ans = max(ans, p2);
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
