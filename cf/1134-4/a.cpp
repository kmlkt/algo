#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    sort(a.begin(), a.end());
    if(a[0] + 1 == a[1] && a[1] + 1 == a[2]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
