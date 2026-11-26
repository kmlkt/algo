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

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), d(n);
    for(int &ai : a) {
        cin >> ai;
    }
    for(int &bi : b) {
        cin >> bi;
    }
    for(int i = 0; i < n; ++i) {
        d[i] = a[i] - b[i];
    }
    sort(d.begin(), d.end());
    int l = 0, r = n - 1;
    ll ans = 0;
    while(l < r) {
        while (d[l] + d[r] > 0 && r > l) {
            --r;
        }
        r = max(r, l);
        ans += n - r - 1;
        ++l;
    }
    while(l < n) {
        ans += n - l - 1;
        ++l;
    }
    cout << ans;
}
