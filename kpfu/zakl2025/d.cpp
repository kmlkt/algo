#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

int progrsum(int n) {
    return n * (n + 1) / 2;
}

const int LIM = 1e6;
array<set<int>, LIM + 1> d;
array<int, LIM + 1> cnt;
array<int, LIM + 1> in;

void build_erat() {
    for (int i = 2; i * i <= LIM; ++i) {
        if (!d[i].empty()) {
            continue;
        }
        for (int j = 2 * i; j <= LIM; j += i) {
            d[j].insert(i);
        }
    }
}

void build_in() {
    for (int i = LIM; i >= 1; --i) {
        in[i] += cnt[i];
        for (int di : d[i]) {
            int p = i / di;
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
