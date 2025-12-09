#include <algorithm>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

using namespace std;
using ll = long long;

char next(char c) {
    if (c == 'z') {
        return 'a';
    }
    return c + 1;
}

char prev(char c) {
    if (c == 'a') {
        return 'z';
    }
    return c - 1;
}

void doo(string &s) {
    int n = s.size();
    if (n % 2) {
        s = "b" + s;
    } else {
        auto s1 = s.substr(0, n / 2);
        auto s2 = s.substr(n / 2, n);
        s = s1 + "a" + s2;
    }
    for (char &c : s) {
        c = next(c);
    }
}

void undo(string &s) {
    for (char &c : s) {
        c = prev(c);
    }
    int n = s.size();
    if (n % 2) {
        auto s1 = s.substr(0, n / 2);
        auto s2 = s.substr(n / 2 + 1, n);
        s = s1 + s2;
    } else {
        s = s.substr(1, n);
    }
}

int main() {
    string s;
    int cmd;
    cin >> s >> cmd;
    if (cmd == 1) {
        doo(s);
        doo(s);
    } else {
        undo(s);
        undo(s);
    }
    cout << s;
}
