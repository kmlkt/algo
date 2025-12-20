#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int n;
string s;
vector<int> pref;

// O(n^3)
void naive() {
    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= i; ++len) {
            bool eq = true;
            for (int j = 0; j < len; ++j) {
                if (s[j] != s[i - len + 1 + j]) {
                    eq = false;
                    break;
                }
            }
            if (eq) {
                pref[i] = len;
            }
        }
    }
}

// O(n)
void optimal() {
    for (int i = 1; i < n; ++i) {
        int &pi = pref[i] = min(pref[i - 1] + 1, i);
        while (pi > 0 && s[pi - 1] != s[i]) {
            --pi;
        }
    }
}

int main() {
    getline(cin, s);
    n = s.size();
    pref.resize(n);
    optimal();
    for (int pi : pref) {
        cout << pi << ' ';
    }
    fill(pref.begin(), pref.end(), 0);
    cout << '\n';
    naive();
    for (int pi : pref) {
        cout << pi << ' ';
    }
}
