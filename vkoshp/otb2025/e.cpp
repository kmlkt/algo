#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> a;
vector<int> l;
int n, q;

int solve() {
    fill(l.begin(), l.end(), 0);
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1] + 1) {
            l[i] = l[i - 1] + 1;
        }
    }
    int r = 0;
    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] == a[i + 1] + 1) {
            ++r;
        } else {
            r = 0;
        }
        ans = max(ans, min(r, l[i]) * 2 + 1);
    }
    return ans;
}

int main() {
    cin >> n;
    a.resize(n);
    l.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << solve() << '\n';
    cin >> q;
    while (q--) {
        int i, x;
        cin >> i >> x;
        a[i - 1] = x;
        cout << solve() << '\n';
    }
}
