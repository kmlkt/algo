#include <algorithm>
#include <array>
#include <cstdint>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1e9;
#define s(i) _s[i - 1]
#define a_cur(i) a[i] - a[l - 1]
#define c_cur(i) c[i] - c[r + 1]
#define ansi(i) min(a_cur(i), c_cur(i)) * 2 + 1
#define ans(j) ansi(b[j])

int main() {
    int n, q;
    cin >> n >> q;
    string _s;
    cin >> _s;
    vector<int> a(n + 2);
    vector<int> c(n + 2);
    vector<int> b(0);
    int b_count = 0;
    for (int i = 1; i <= n; ++i) {
        switch (s(i)) {
        case 'b':
            ++b_count;
            break;
        case 'c':
            ++c[1];
            break;
        }
    }
    b.reserve(b_count);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i - 1];
        c[i + 1] = c[i];
        switch (s(i)) {
        case 'a':
            ++a[i];
            break;
        case 'b':
            b.push_back(i);
            break;
        case 'c':
            --c[i + 1];
            break;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int stupid = 0;
        for (int i = l; i <= r; ++i) {
            if (s(i) == 'b') {
                stupid = max(stupid, ansi(i));
            }
        }

        int v = lower_bound(b.begin(), b.end(), l) - b.begin();
        int u = upper_bound(b.begin(), b.end(), r) - b.begin();
        if (v >= u) {
            cout << "0" << '=' << stupid << '\n';
            continue;
        }
        while (v < u - 1) {
            int m1 = v + (u - v) * 1 / 3;
            int m2 = v + (u - v) * 2 / 3;
            if ((ans(m1) < ans(m2))) {
                v = m1 + 1;
            } else {
                u = m2;
            }
        }
        cout << ans(v) << '=' << stupid << '\n';
    }
}
