#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

char solve() {
    int n, k;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    vector<int> propitup(n, -1);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            continue;
        }
        int d = min(a[i] - 1, i);
        propitup[i - d] = max(propitup[i - d], i);
    }
    int ans = 0;
    int last = -1;
    vector<bool> propit(n);
    for (int i = 0; i < n; ++i) {
        last = max(last, propitup[i]);
        propit[i] = i <= last;
    }
    for (bool ansi : propit) {
        cout << ansi << ' ';
    }
    return ' ';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
