#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct monster {
    int a, x;
    bool operator<(monster other) {
        return x < other.x;
    }
};

vector<monster> m;

bool solve() {
    int n, k;
    cin >> n >> k;
    m.resize(n);
    for (monster &mi : m) {
        cin >> mi.a;
    }
    for (monster &mi : m) {
        cin >> mi.x;
        if (mi.x < 0) {
            mi.x = -mi.x;
        }
    }
    sort(m.begin(), m.end());
    int e = 0;
    for (int t = 0; t < n; ++t) {
        int p = k;
        while (e < n) {
            monster &cur = m[e];
            if (cur.a > p) {
                cur.a -= p;
                p = 0;
                break;
            }
            p -= cur.a;
            ++e;
        }
        if (e >= n) {
            break;
        }
        if (m[e].x <= t + 1) {
            return 0;
        }
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
