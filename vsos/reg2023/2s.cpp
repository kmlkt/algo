#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;

bool u(int l, int c) {
    for (int i = l; i < c; ++i) {
        if (a[i] >= a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool d(int c, int r) {
    for (int i = c; i < r; ++i) {
        if (a[i] <= a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool bitonic(int l, int r) {
    for (int c = l; c <= r; ++c) {
        if (u(l, c) && d(c, r)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int ans = 0;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            if (bitonic(l, r)) {
                ++ans;
            }
        }
    }
    cout << ans;
}
