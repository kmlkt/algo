#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n;
string s;
vector<int> z;
vector<int> pref;

// O(n^2)
void naive() {
    for (int i = 1; i < n; ++i) {
        int &zi = z[i];
        while (i + zi < n && s[i + zi] == s[zi]) {
            ++zi;
        }
    }
}

// O(n)
void frompref() {
    for (int i = 1; i < n; ++i) {
        int &pi = pref[i] = min(pref[i - 1] + 1, i - 1);
        while (pi > 0 && s[pi - 1] != s[i]) {
            --pi;
        }
        if (pi == 0) {
            continue;
        }
        int &zi = z[i + 1 - pi];
        zi = max(zi, pi);
    }
}

int e(int i) {
    return i + z[i];
}

// O(n)
void optimal() {
    int mx = 0;
    for (int i = 1; i < n; ++i) {
        int &zi = z[i];
        if (i < e(mx)) {
            zi = min(e(mx) - i, z[i - mx]);
        }

        while (e(i) < n && s[zi] == s[e(i)]) {
            ++zi;
        }

        if (e(i) > e(mx)) {
            mx = i;
        }
    }
}

int main() {
    getline(cin, s);
    n = s.size();
    z.resize(n);
    pref.resize(n);
    optimal();
    for (int pi : z) {
        cout << pi << ' ';
    }
    cout << '\n';
    fill(z.begin(), z.end(), 0);
    frompref();
    for (int pi : z) {
        cout << pi << ' ';
    }
    cout << '\n';
    fill(z.begin(), z.end(), 0);
    naive();
    for (int pi : z) {
        cout << pi << ' ';
    }
}
