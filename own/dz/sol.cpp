#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct chel {
    int i, v;
    bool operator<(chel other) {
        return v < other.v;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<chel> a(n);
    vector<chel> b(m);
    for (int i = 0; i < n; ++i) {
        chel &ai = a[i];
        ai.i = i;
        cin >> ai.v;
    }
    for (int i = 0; i < m; ++i) {
        chel &bi = b[i];
        bi.i = i;
        cin >> bi.v;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        chel ai = a[i];
        chel bj = b[j];
        if (ai.v <= bj.v) {
            ++i;
            ++j;
        } else {
            ++j;
        }
    }
    cout << ((i == n) ? "YES" : "NO");
}
//
