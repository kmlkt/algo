#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void add(int *&from, int *&to) {
    *to = *from;
    ++from;
    ++to;
}

void morge(int *al, int *ar, int *bl, int *br, int *ans) {
    while (al < ar && bl < br) {
        if (*al < *bl) {
            add(al, ans);
        } else {
            add(bl, ans);
        }
    }
    while (al < ar) {
        add(al, ans);
    }
    while (bl < br) {
        add(bl, ans);
    }
}

void sord(int *l, int *r, int *buf) {
    int n = r - l;
    if (n <= 1) {
        return;
    }
    int *m = l + n / 2;
    sord(l, m, buf);
    sord(m, r, buf);
    morge(l, m, m, r, buf);
    for (int i = 0; i < n; ++i) {
        l[i] = buf[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> buf(n);
    for (int &ai : a) {
        cin >> ai;
    }
    sord(a.begin().base(), a.end().base(), buf.begin().base());
    for (int ai : a) {
        cout << ai << ' ';
    }
}
