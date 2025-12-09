#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;
vector<int> diffl;
vector<int> diffr;

void solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    diffl.resize(n);
    diffr.resize(n);
    sort(a.begin(), a.end());
    int same = 1;
    for (int i = 1; i < n; ++i) {
        diffl[i] = diffl[i - 1];
        if (a[i] == a[i - 1]) {
            ++same;
        } else {
            diffl[i] += same;
            same = 1;
        }
    }
    same = 1;
    for (int i = n - 2; i >= 0; --i) {
        diffr[i] = diffr[i + 1];
        if (a[i] == a[i + 1]) {
            ++same;
        } else {
            diffr[i] += same;
            same = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += diffl[i] * diffr[i];
    }
    cout << ans << "\n";
}

int main() {
    a.reserve(1'00'000);
    diffl.reserve(1'00'000);
    diffr.reserve(1'00'000);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
