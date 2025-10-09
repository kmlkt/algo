#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, m, l;
vector<vector<int>> a;
vector<vector<int>> b;

int f(vector<int> &ai, vector<int> &bj, int k) {
    return max(ai[k], bj[k]);
}

int main() {
    cin >> n >> m >> l;
    a.resize(n, vector<int>(l));
    b.resize(m, vector<int>(l));
    for (auto &ai : a) {
        for (int &aij : ai) {
            cin >> aij;
        }
    }
    for (auto &bi : b) {
        for (int &bij : bi) {
            cin >> bij;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int i, j;
        cin >> i >> j;
        --i;
        --j;
        vector<int> &ai = a[i];
        vector<int> &bj = b[j];
        ll r = l; // f(l) >= f(m) < f(r)
        ll l = 0;
        while (r - l > 1) {
            ll m1 = l + (r - l) / 3;
            if (m1 == l) {
                ++m1;
            }
            ll m2 = l + (r - l) * 2 / 3;
            int f1 = f(ai, bj, m1);
            int f2 = f(ai, bj, m2);
            if (f1 > f2) {
                l = m1;
            } else {
                r = m2;
            }
        }
        cout << l + 2 << "\n";
    }
}
