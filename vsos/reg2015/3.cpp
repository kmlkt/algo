#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

const int k = 28;

struct seq {
    char c;
    int n;
};

template <typename T>
T &last(vector<T> &a) {
    return a[a.size() - 1];
}

int main() {
    vector<seq> a;
    string s;
    cin >> s;
    int n = s.size();
    a.push_back({s[0], 1});
    for (int i = 1; i < n; ++i) {
        if (last(a).c != s[i]) {
            a.push_back({s[i], 0});
        }
        ++last(a).n;
    }
    int m = a.size();
    map<char, map<int, map<char, int>>> d;
    for (int i = 0; i < n - 1; ++i) {
        seq &cur = a[i];
        seq &next = a[i + 1];
        int &di = d[cur.c][cur.n][next.c];
        di = max(di, next.n);
    }
    map<char, int> same;
    for (int i = 0; i < n; ++i) {
        seq &cur = a[i];
        int &si = same[cur.c];
        si = max(si, cur.n);
    }
    ll ans = 0;
    for (auto &[ac, da] : d) {
        for (auto &[an, dan] : da) {
            for (auto &[bc, bn] : dan) {
            }
        }
    }
}
