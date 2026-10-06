#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct pike {
    int i = -1;
    ll x, h;

    bool operator<(pike &another) {
        return x < another.x;
    }
};

int main() {
    int n;
    cin >> n;
    vector<pike> pikes(n);
    for (int i = 0; i < n; ++i) {
        pikes[i].i = i;
    }
    for (pike &p : pikes) {
        cin >> p.x;
    }
    for (pike &p : pikes) {
        cin >> p.h;
    }
    sort(pikes.begin(), pikes.end());

    for (int i = 1; i < n; ++i) {
        pike &p = pikes[i - 1];
        pike &q = pikes[i];
        pike g;
        g.x = ((q.x + p.x) + (p.h - q.h)) / 2;
        g.h = ((q.h + p.h) + (p.x - q.x)) / 2;
        if (g.x != p.x && g.x != q.x) {
            pikes.push_back(g);
        }
    }
    sort(pikes.begin(), pikes.end());
    int m = pikes.size();

    vector<int> prev_higher(m);
    for (int i = 0; i < m; ++i) {
        prev_higher[i] = i - 1;
        while (prev_higher[i] != -1 && pikes[prev_higher[i]].h < pikes[i].h) {
            prev_higher[i] = prev_higher[prev_higher[i]];
        }
    }
    vector<int> next_higher(m);
    for (int i = m - 1; i >= 0; --i) {
        next_higher[i] = i + 1;
        while (next_higher[i] != m && pikes[next_higher[i]].h < pikes[i].h) {
            next_higher[i] = next_higher[next_higher[i]];
        }
    }
    vector<int> prev_lower(m);
    for (int i = 0; i < m; ++i) {
        prev_lower[i] = i - 1;
        while (prev_lower[i] != -1 && pikes[prev_lower[i]].h > pikes[i].h) {
            prev_lower[i] = prev_higher[prev_lower[i]];
        }
    }
    vector<int> next_lower(m);
    for (int i = m - 1; i >= 0; --i) {
        next_lower[i] = i + 1;
        while (next_lower[i] != m && pikes[next_lower[i]].h > pikes[i].h) {
            next_lower[i] = next_higher[next_lower[i]];
        }
    }
    vector<ll> closest(n, INT64_MAX);
    for (int j = 0; j < m; ++j) {
        pike &p = pikes[j];
        if (p.i == -1) {
            continue;
        }
        if (prev_higher[j] != -1) {
            pike &q = pikes[prev_higher[j]];
            ll dh = q.h - p.h;
            ll ix = q.x + dh;
            if (ix != p.x) {
                closest[p.i] = min(closest[p.i], p.x - ix);
            }
        }
        if (next_higher[j] != m) {
            pike &q = pikes[next_higher[j]];
            ll dh = q.h - p.h;
            ll ix = q.x - dh;
            if (ix != p.x) {
                closest[p.i] = min(closest[p.i], ix - p.x);
            }
        }
        if (prev_lower[j] != -1) {
            pike &q = pikes[prev_lower[j]];
            ll dh = p.h - q.h;
            ll ix = q.x + dh;
            if (ix != p.x) {
                closest[p.i] = min(closest[p.i], p.x - ix);
            }
        }
        if (next_lower[j] != m) {
            pike &q = pikes[next_lower[j]];
            ll dh = p.h - q.h;
            ll ix = q.x - dh;
            if (ix != p.x) {
                closest[p.i] = min(closest[p.i], ix - p.x);
            }
        }
        if (closest[p.i] == INT64_MAX) {
            closest[p.i] = -1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << closest[i] << '\n';
    }
}
