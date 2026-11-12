#include <algorithm>
#include <iostream>
#include <map>
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
    vector<int> z(n);
    map<int, vector<int>> ind;
    for(int i = 0; i + 4 < n; ++i) {
        z[i] = a[i] + a[i + 2] - a[i + 4];
        ind[z[i]].push_back(i);
    }
    ll ans = 0;
    for(auto &[zi, in] : ind) {
        for(int i : in) {
            ans += upper_bound(in.begin(), in.end(), i - 1) - in.begin();
            if(i >= 2 && z[i - 2] == zi) {
                --ans;
            }
            if(i >= 4 && z[i - 4] == zi) {
                --ans;
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
