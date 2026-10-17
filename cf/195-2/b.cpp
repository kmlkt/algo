#include <iostream>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> g;
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(s[i - 1] != s[i]) {
            g.push_back({cnt});
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    g.push_back({cnt});

    bool minus1 = false;
    bool plus1 = false;
    for(int i = 0; i < g.size(); ++i) {
        if(g[i] == 1 && i != 0 && i != g.size() - 1) {
            minus1 = true;
        }
        if(g[i] >= 3) {
            plus1 = true;
        }
    }
    cout << 1 + minus1 + plus1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
