#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int progrsum(int n) {
    return n * (n + 1) / 2;
}

const int LIM = 1e6;
array<int, LIM + 1> erat;
array<int, LIM + 1> p;
array<vector<int>, LIM + 1> to;
array<int, LIM + 1> in;
array<int, LIM + 1> cnt;
array<vector<int>, LIM + 1> ch;
array<int, LIM + 1> ans;
vector<pair<int, int>> surf;

void build_erat() {
    erat.fill(1);
    for (int i = 2; i * i <= LIM; ++i) {
        if (erat[i] != 1) {
            continue;
        }
        for (int j = 2 * i; j <= LIM; j += i) {
            if (erat[j] == 1) {
                erat[j] = i;
            }
        }
    }
    for (int i = 2; i <= LIM; ++i) {
        if (erat[i] == 1) {
            p[i] = 1;
        } else {
            p[i] = i / erat[i];
        }
    }
    for (int i = 2; i <= LIM; ++i) {
        to[p[i]].push_back(i);
    }
}

void build_in() {
    for (int i = LIM; i >= 1; --i) {
        in[i] += cnt[i];
        in[p[i]] += in[i];
    }
    for (int i = 1; i <= LIM; ++i) {
        if (in[p[i]] > in[i] && in[i] != 0) {
            ch[p[i]].push_back(in[i]);
        }
        if (cnt[i] != 0) {
            ch[i].push_back(cnt[i]);
        }
    }
    for (int i = 1; i <= LIM; ++i) {
        int n = ch[i].size();
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                ans[i] += ch[i][j] * ch[i][k];
            }
        }
    }
    for (int i = 1; i <= LIM; ++i) {
        if (ans[i] != 0) {
            surf.push_back({i, ans[i]});
        }
    }
}

int main() {
    build_erat();
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
        ++cnt[ai];
    }
    build_in();
    for (auto &[i, bi] : surf) {
        cout << i << ' ' << bi << '\n';
    }
}
