#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

vector<int> a;

int first(int x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

int last(int x) {
    return x % 10;
}

bool ok(int x) {
    while (x != 0) {
        if ((x / 10) % 10 > x % 10) {
            return 0;
        }
        x /= 10;
    }
    return 1;
}

bool solve() {
    int n;
    cin >> n;
    a.resize(n);
    for (int &ai : a) {
        cin >> ai;
    }
    int prev = a[0];
    if (ok(prev)) {
        prev = last(prev);
    }
    for (int i = 1; i < n; ++i) {
        int x = a[i];
        if (x < prev) {
            return 0;
        }
        if (first(x) >= prev && ok(x)) {
            x = last(x);
        }
        prev = x;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
