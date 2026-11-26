#include <algorithm>
#include <array>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int N = 100000;
array<char, N + 1> is_composite;
array<int, N + 1> nextprime;

void solve() {
    int d;
    cin >> d;
    int k1 = nextprime[1 + d];
    int k2 = nextprime[k1 + d];
    cout << k1 * k2 << '\n';
}


int main() {
    for(int i = 2; i <= N; ++i) {
        if(!is_composite[i]) {
            for(int j = i * 2; j <= N; j += i) {
                is_composite[j] = 1;
            }
        }
    }
    is_composite[0] = is_composite[1] = 1;
    for(int i = N - 1; i >= 0; --i) {
        nextprime[i] = is_composite[i] ? nextprime[i + 1] : i;
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
