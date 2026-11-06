#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
    }
    sort(a.begin(), a.end());
    if(k != n && a.front() == a.back()) {
        cout << "NO\n";
        return;
    }
    rotate(a.begin(), a.end() - k, a.end());
    reverse(a.begin() + k, a.end());
    if(k != n && a[k - 1] == a[k]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int ai : a) {
        cout << ai << ' ';
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
