#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
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
    sort(a.begin(), a.end(), greater<>());
    ll w = 0;
    ll h = 0;
    for(int ai : a) {
        if(w <= h) {
            w += (1LL << ai);
        } else {
            h += (1LL << ai);
        }
    }
    cout << w * h << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
