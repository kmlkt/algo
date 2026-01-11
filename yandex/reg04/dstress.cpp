#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

vector<int> bas{1, 2, 3, 4, 5, 6, 7};
vector<vector<int>> a(7, bas);

bool ok(int n) {
    set<int> col;
    for (int j = 0; j < n; ++j) {
        col.clear();
        for (int i = 0; i < n; ++i) {
            int x = a[i][j];
            if (x > n) {
                return false;
            }
            col.insert(x);
        }
        if (col.size() != n) {
            return false;
        }
    }
    return true;
}

void print() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void check() {
    if (ok(5) && ok(2)) {
        print();
        exit(0);
    }
}

const int f7 = 7 * 7;

void build_row(int r) {
    if (r == 7) {
        check();
        return;
    }
    for (int i = 0; i < f7; ++i) {
        build_row(r + 1);
        next_permutation(a[r].begin(), a[r].end());
    }
}

int main() {
    build_row(0);
    cout << "NF";
}
