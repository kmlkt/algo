#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int LIM = 100;
using bs = bitset<LIM + 1>;

array<bool, LIM + 1> prime;
array<bs, LIM + 1> divider;

int n;
int variants = 0;
bs w;

int dist(vector<int> &path) {
    int ans = 0;
    for (int &pi : path) {
        ans += pi;
    }
    return ans;
}

void build_erat() {
    prime.fill(1);
    for (int i = 2; i * i <= LIM; ++i) {
        if (!prime[i]) {
            continue;
        }
        prime[i] = 1;
        divider[i][i] = 1;
        for (int j = 1 * i; j <= LIM; j += i) {
            divider[j] |= divider[i];
        }
    }
}

bool can(int x, bs &m) {
    return (divider[x] & m).none();
}

void add(int x, bs &m) {
    m |= divider[x];
}

void rem(int x, bs &m) {
    m &= ~divider[x];
}

void go(bs &m, int d, int next) {
    if (!can(next, m)) {
        return;
    }
    d += next;
    if (w[d - 1]) {
        return;
    }
    if (d == n) {
        ++variants;
        return;
    }
    add(next, m);
    for (int x = 1; x <= (n - d); ++x) {
        go(m, d, x);
    }
    rem(next, m);
}

int main() {
    build_erat();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int wi;
        cin >> wi;
        w[i] = wi;
    }
    bs m;
    go(m, 1, 0);
    cout << variants;
}
