#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = INT32_MAX;

int before(char *s, char c) {
    int ans = 0;
    while (*s != 0) {
        if (*s == c) {
            return ans;
        }
        ++ans;
        ++s;
    }
    return INF;
}

bool get(int mask, int i) {
    return mask & (1 << i);
}

char get(string &a, int i) {
    if (i < a.size()) {
        return a[i];
    }
    return ' ';
}

int set(int mask, int i, bool v) {
    bool cur = get(mask, i);
    if (cur == v) {
        return mask;
    }
    if (v) {
        return mask | (1 << i);
    } else {
        return mask - (1 << i);
    }
}

bool compare(string &a, int amask, string &b, int bmask) {
    int acur = 0;
    int bcur = 0;
    while (acur < a.size() || bcur < b.size()) {
        bool j = get(amask, acur);
        if (!get(amask, acur) && acur < a.size()) {
            ++acur;
            continue;
        }
        if (!get(bmask, bcur) && bcur < b.size()) {
            ++bcur;
            continue;
        }
        if (get(a, acur) != get(b, bcur)) {
            return false;
        }
        ++acur;
        ++bcur;
    }
    return true;
}

int dist(string &a, int mask) {
    int ans = 0;
    for (int cur = 0; cur < a.size(); ++cur) {
        if (!get(mask, cur)) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    compare(s, 3, t, 5);
    int slim = 1 << s.size();
    int tlim = 1 << t.size();
    int ans = INF;
    for (int smask = 0; smask < slim; ++smask) {
        for (int tmask = 0; tmask < tlim; ++tmask) {
            if (compare(s, smask, t, tmask)) {
                ans = min(ans, dist(s, smask) + dist(t, tmask));
            }
        }
    }
    cout << ans;
}

/*
 * char *s = _s.data();
 char *t = _t.data();
 int ans = 0;
 while (*s != 0 && *t != 0) {
     int sdist = before(s, t[0]);
     int tdist = before(t, s[0]);
     if (sdist == INF && tdist == INF) {
         break;
     }
     if (sdist < tdist) {
     }
 }
 */
