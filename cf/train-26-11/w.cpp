#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void or_rotate(bitset<1024> &b, int m, int x) {
    b |= (b << x) | (b >> (m - x));
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for(int i = 0; i < n; ++i) {
        int ai;
        cin >> ai;
        a.push_back(ai % m);
    }
    // for(auto [ai, c] : cnt) {
    //     for(int i = 1; i <= c; ++i) {
    //         a.insert((ai * i) % m);
    //     }
    // }
    // if(a.count(0)) {
    //     cout << "YES";
    //     return 0;
    // }
    bitset<1024> b;
    for(int ai : a) {
        or_rotate(b, m, ai);
        b[ai] = 1;
    }
    bool ans = b[0];
    cout << (ans ? "YES" : "NO");
}
