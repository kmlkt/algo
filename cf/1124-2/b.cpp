#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<ll>> a;

int solve() {
    int n;
    cin >> n;
    a.resize(n);
    set<int> tmp;
    for(auto &ai : a) {
        ai.clear();
        tmp.clear();
        ll x;
        cin >> x;
        while(tmp.count(x) == 0) {
            ai.push_back(x);
            tmp.insert(x);
            ll s = 0;
            while(x > 0) {
                s += (x % 10) * (x % 10);
                x /= 10;
            }
            x = s;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {

        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
