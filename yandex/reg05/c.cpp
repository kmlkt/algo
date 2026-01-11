#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct help {
    int b, k;
    string s;
};

int n, q;
vector<array<char, 2>> s;
vector<array<int, 2>> p;
vector<help> a;

int set(int i, char c) {
    auto &si = s[i];
    if (si[0] == 0 || si[0] == c) {
        si[0] = c;
        return 0;
    }
    if (si[1] == 0 || si[1] == c) {
        si[1] = c;
        return 1;
    }
    return -1;
}

bool try_set(int i, char c) {
    auto &si = s[i];
    if (si[0] == 0 || si[0] == c) {
        return true;
    }
    if (si[1] == 0 || si[1] == c) {
        return true;
    }
    return false;
}

bool try_set_direct(help &h) {
    for (int i = 0; i < h.k; ++i) {
        if (!try_set(h.b + i, h.s[i])) {
            return false;
        }
    }
    int prev = 0;
    for (int i = 0; i < h.k; ++i) {
        int cur = set(h.b + i, h.s[i]);
        if (i != 0) {
            p[i][cur] = prev;
        }
        prev = cur;
    }
    return true;
}

bool try_set(help &h) {
    bool ans = false;
    ans |= try_set_direct(h);
    reverse(h.s.begin(), h.s.end());
    ans |= try_set_direct(h);
    reverse(h.s.begin(), h.s.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    s.resize(n);
    a.resize(q);
    for (help &ai : a) {
        cin >> ai.b >> ai.k >> ai.s;
    }
}
