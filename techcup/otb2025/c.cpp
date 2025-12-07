#include <algorithm>
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector<bool> a;
vector<int> pairs;
vector<int> mut[2];
vector<int> ost[2];
vector<int> canmut[2][3];
vector<int> cnt[2][3];

void build_pairs() {
    pairs.resize(a.size());
    for (int i = 0; i < a.size() - 1; ++i) {
        pairs[i] = a[i] + a[i + 1] * 2;
    }
    pairs[a.size() - 1] = a[a.size() - 1];
}

void build_mut(int d) {
    auto &m = mut[d];
    m.resize(a.size() - 1 - d);
    for (int i = 0; i < a.size() - d - 1; ++i) {
        int pi = (i - d) - ((i - d) % 2) + d;
        int p = pairs[pi];
        int &imut = m[i];
        if (i % 2 == d % 2) {
            if (p == 0 || p == 3) {
                imut = 0;
            } else if (p == 2) {
                imut = 2;
            } else if (p == 1) {
                imut = 1;
            }
        } else {
            if (pi + 2 >= pairs.size()) {
                cout << "AA";
            }
            int pnext = pairs[pi + 2];
            int old = pnext + p;
            if (p >= 2 && pnext % 2 == 0) {
                ++pnext;
                p -= 2;
            }
            if (p < 2 && pnext % 2 == 1) {
                --pnext;
                p += 2;
            }
            imut = ((pnext + p) - old + 6) % 3;
        }
    }
}

void build_ost(int d) {
    auto &o = ost[d];
    o.resize(a.size() - d);
    for (int i = d; i < a.size(); ++i) {
        auto &oi = o[i - d];
        if (i % 2 == d % 2) {
            oi = a[i];
            if (i != d) {
                oi += o[i - d - 1];
            }
        } else {
            oi = pairs[i - 1];
            if (i != d + 1) {
                oi += o[i - d - 2];
            }
        }
        oi %= 3;
    }
}

void build_cnt(int d, int y) {
    auto &cm = canmut[d][y];
    auto &m = mut[d];
    cm.resize(m.size());
    cnt[d][y].resize(m.size());
    for (int i = 0; i < m.size(); ++i) {
        cm[i] = m[i] == y;
    }
    partial_sum(cm.begin(), cm.end(), cnt[d][y].begin());
}

int get_ost(int l, int r) {
}

void solve() {
    int l = 1, r = a.size();
    cin >> l >> r;
    int ostt = ost[0][a.size() - 1];
    cout << cnt[0][3 - ostt][a.size() - 2] << "\n";
}

int main() {
    string s;
    cin >> s;
    a.resize(s.size());
    for (int i = 0; i < s.size(); ++i) {
        a[i] = s[i] == '1';
    }
    reverse(a.begin(), a.end());
    build_pairs();
    build_mut(0);
    build_mut(1);
    build_ost(0);
    build_ost(1);
    for (int i = 0; i < 3; ++i) {
        build_cnt(0, i);
        build_cnt(1, i);
    }
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
