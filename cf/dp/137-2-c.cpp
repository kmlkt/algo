#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;
vector<int> dp_back;
vector<int> dp_none;
string s;

const int INF = 1e8;

int solve() {
    int n;
    cin >> n;
    cin >> s;
    a.resize(n);
    dp_back.resize(n);
    dp_none.resize(n);
    fill(dp_back.begin(), dp_back.end(), -INF);
    for (int &ai : a) {
        cin >> ai;
    }
    dp_none[0] = (s[0] == '1') * a[0];
    for (int i = 1; i < n; ++i) {
        bool closed = s[i] == '1';
        bool prevclosed = s[i - 1] == '1';
        if (closed) {
            dp_none[i] = max(dp_none[i - 1], dp_back[i - 1]) + a[i];
            dp_back[i] = (prevclosed ? dp_back[i - 1] : dp_none[i - 1]) + a[i - 1];
        } else {
            dp_none[i] = max({dp_none[i - 1], dp_back[i - 1]});
        }
        // cout << dp_back[i] << ' ' << dp_none[i] << '\n';
    }
    return max(dp_back[n - 1], dp_none[n - 1]);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
