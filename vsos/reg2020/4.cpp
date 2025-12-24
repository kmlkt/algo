#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct fragment {
    ll l;
    ll r;
    ll d = 0;
    fragment(ll s, vector<ll> &p) {
        int m = p.size();
        if (m > 1) {
            d = p[1] - p[0];
            for (int i = 2; i < m; ++i) {
                if (p[i] - p[i - 1] != d) {
                    d = -1;
                    return;
                }
            }
        }
        l = p[0];
        r = s - p[m - 1];
    }
    fragment(fragment &a, fragment &b) {
        if (a.d == -1 || b.d == -1) {
            d = -1;
            return;
        }
        if (a.d == 0 || b.d == 0 || a.d == b.d) {
            d = a.d | b.d;
        } else {
            d = -1;
            return;
        }
        if (d == 0) {
            d = a.r + b.l;
        } else if (d != a.r + b.l) {
            d = -1;
            return;
        }
        l = a.l;
        r = b.r;
    }
};

int n;
vector<fragment> f;

void check(int a, int b) {
    fragment x(f[a], f[b]);
    for (int i = 0; i < n; ++i) {
        if (x.d == -1) {
            break;
        }
        fragment &fi = f[i];
    }
}

int main() {
    cin >> n;
    f.resize(n);
    vector<ll> p;
    p.reserve(100'000);
    for (auto &fi : f) {
        int m;
        ll s;
        cin >> m >> s;
        p.resize(m);
        for (ll &pi : p) {
            cin >> pi;
        }
        fi = fragment(s, p);
    }
}
