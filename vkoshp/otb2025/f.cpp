#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> s;
bool last = 0;
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ll si;
        cin >> si;
        if (si != 2 && si % 2 == 0) {
            ans += 3;
        } else {
            ++ans;
        }
    }
    cout << ((last + ans) % 2 ? "Yes" : "No") << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
