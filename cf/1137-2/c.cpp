#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
        --ai;
    }
    vector<int> lsmaller(n);
    vector<int> rsmaller(n);
    for(int i = 0; i < n; ++i) {
        lsmaller[i] = i - 1;
        while (lsmaller[i] >= 0 && a[lsmaller[i]] > a[i]) {
            lsmaller[i] = lsmaller[lsmaller[i]];
        }
    }
    for(int i = n-1; i >= 0; --i) {
        rsmaller[i] = i + 1;
        while (rsmaller[i] < n && a[rsmaller[i]] > a[i]) {
            rsmaller[i] = rsmaller[rsmaller[i]];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        if(rsmaller[i] == i+1 && lsmaller[i] == i-1){
            ++ans;
        } else if(rsmaller[i] == i+1) {
            ans += i - lsmaller[i];
        } else if(lsmaller[i] == i-1) {
            ans += rsmaller[i] - i;
        } else {
            ans += 2;
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
