#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n;
string s;
vector<int> r;

// O(n^2)
void naive() {
    for (int i = 0; i < n; ++i) {
        int &ri = r[i];
        while (ri <= i && s[i - ri] == s[i + ri]) {
            ++ri;
        }
    }
}

int b(int i) {
    return i - r[i];
}

int e(int i) {
    return i + r[i];
}

// O(n)
void optimal() {
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        int &ri = r[i];
        if (i < e(mx)) {
            ri = min(e(mx) - i, r[mx - (i - mx)]);
        }
        while (b(i) >= 0 && e(i) < n && s[b(i)] == s[e(i)]) {
            ++ri;
        }
        if (e(i) > e(mx)) {
            mx = i;
        }
    }
}

int main() {
    string ss;
    getline(cin, ss);
    n = ss.size() * 2 - 1;
    s.resize(n, '#');
    for (int i = 0; i < ss.size(); ++i) {
        s[i * 2] = ss[i];
    }
    r.resize(n);
    optimal();
    for (int pi : r) {
        cout << pi << ' ';
    }
    cout << '\n';
    fill(r.begin(), r.end(), 0);
    naive();
    for (int pi : r) {
        cout << pi << ' ';
    }
}
