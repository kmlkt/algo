#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int *b;

int *part(int *l, int *r, int x) {
    int li = l - b;
    int ri = r - b;
    --r;
    while (l <= r) {
        if (*l > x) {
            swap(*l, *r);
            --r;
        } else if (*r < x) {
            swap(*l, *r);
            ++l;
        } else {
            ++l;
            --r;
        }
    }
    return r;
}

void sord(int *l, int *r) {
    int n = r - l;
    if (n <= 1) {
        return;
    }
    int *x = l + n / 2;
    int *m = part(l, r, *x);
    sord(l, m);
    sord(m, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    b = a.begin().base();
    sord(a.begin().base(), a.end().base());
    for (int ai : a) {
        cout << ai << ' ';
    }
}
