#include <algorithm>
#include <iostream>
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
    sort(a.begin(), a.end());
    vector<int> l, r;
    int ans = 0;
    for(int ai : a) {
        if(l.empty() || l.back() != ai) {
            ++ans;
            l.push_back(ai);
        } else {
            if(r.empty() || r.back() != ai) {
                ++ans;
            }
            r.push_back(ai);
        }
    }
    reverse(r.begin(), r.end());
    cout << ans << '\n';
    for(int li : l) {
        cout << li << ' ';
    }
    for(int ri : r) {
        cout << ri << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
