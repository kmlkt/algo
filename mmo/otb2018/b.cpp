#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
using namespace std;

struct suffix {
    int index;
    pair<int, int> rank;
    bool operator<(suffix another) {
        return rank < another.rank;
    }
};

int pow2(int x) {
    return 1 << x;
}

vector<vector<int>> buildSparseTable(vector<int> input, function<int(int, int)> f) {
    int sz = input.size();
    int h = ceil(log2(sz));
    vector<vector<int>> st(h);
    st[0] = input;
    for (int i = 1; i < h; ++i) {
        int step = pow2(i - 1);
        st[i] = vector<int>(st[i - 1].size() - step);
        for (int j = 0; j < st[i].size(); ++j) {
            st[i][j] = f(st[i - 1][j], st[i - 1][j + step]);
        }
    }
    return st;
}

int main() {
    vector<int> a{-10, 0, -5, 30, 4, 2, 3, 2, 2};
    auto smax = buildSparseTable(a, [](int l, int r) { return max(l, r); });
    for (auto si : smax) {
        for (auto sij : si) {
            cout << sij << ' ';
        }
        cout << endl;
    }
    cout << endl;
    auto smin = buildSparseTable(a, [](int l, int r) { return min(l, r); });
    for (auto si : smin) {
        for (auto sij : si) {
            cout << sij << ' ';
        }
        cout << endl;
    }
}
