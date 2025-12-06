#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

int n, m, l;
vector<vector<int>> a;
vector<vector<int>> b;

bool check(vector<int> &ai, vector<int> &bj, int k) {
    return ai[k] <= bj[k];
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
        int rr = l;
        int ll = -1;
        while (rr - ll > 1) {
            int m = (ll + rr) / 2;
            if (check(ai, bj, m)) {
                ll = m;
            } else {
                rr = m;
            }
        }
        if (ll == -1) {
            ll = 0;
        }
        if (rr == l) {
            rr = l - 1;
        }
        int ansc = max(ai[ll], bj[ll]) < max(ai[rr], bj[rr]) ? ll : rr;
        cout << ansc + 1 << "\n";
    }
}
