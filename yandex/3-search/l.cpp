#include <algorithm>
#include <cerrno>
#include <cinttypes>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>
using namespace std;
int A;

map<int, int> cache;

int input(int q) {
    if (cache.find(q) == cache.end()) {
        cout << "? " << q + 1 << endl;
        cin >> cache[q];
    }
    return cache[q];
}

bool lInv(int d) {
    if (d < 0) {
        return true;
    }
    int l = input(d - d % 2);
    int r = input(d - d % 2 + 1);
    return l == r;
}

int main() {
    cin >> A;
    int l = -2;
    int r = A - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (lInv(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    int ans = input(r);
    cout << "! " << ans;
}
