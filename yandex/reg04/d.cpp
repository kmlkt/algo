#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

vector<vector<int>> t;

void from_scratch(int offset, int zero, int n) {
    for (int j = 0; j < n; ++j) {
        t[0][offset + j] = (zero + j);
    }
    for (int i = 1; i < n; ++i) {
        auto src = offset + t[i - 1].begin();
        auto dst = offset + t[i].begin();
        rotate_copy(src, src + 1, src + n, dst);
    }
}

void print(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << t[i][j] << ' ';
        }
        cout << '\n';
    }
}

void copy(int i0, int j0, int i1, int j1, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            t[i1 + i][j1 + j] = t[i0 + i][j0 + j];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int mx = a[a.size() - 1];
    t.resize(mx, vector<int>(mx));
    from_scratch(0, 1, a[0]);
    for (int i = 1; i < n; ++i) {
        int prev = a[i - 1];
        int cur = a[i];
        if (cur == 2 * prev) {
            from_scratch(prev, prev + 1, prev);
            copy(0, 0, prev, prev, prev);
            copy(0, prev, prev, 0, prev);
        } else if (cur)
    }
    cout << "Yes" << '\n';
    print(mx);
}
