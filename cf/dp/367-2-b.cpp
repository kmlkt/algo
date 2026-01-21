#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for (int &xi : x) {
        cin >> xi;
    }
    sort(x.begin(), x.end());
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        int ans = upper_bound(x.begin(), x.end(), m) - x.begin();
        cout << ans << '\n';
    }
}
