#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
}

int main() {
    int N = 1000000;
    vector<bool> prime(N);
    vector<bool> cubesum(N);
    prime[1] = prime[2] = 1;
    for(int i = 2; i * i < N; ++i) {
        if(!prime[i]) {
            continue;
        }
        for(int j = i * 2; j < N; j += i) {
            prime[j] = 0;
        }
    }
    for(int i = 0; i * i * i < N; ++i) {
        for(int j = 0; i * i * i + j * j * j < N; ++j) {
            cubesum[i * i * i + j * j * j] = 1;
        }
    }

    for(int i = 1; i < N; ++i) {
        if(prime[i] && cubesum[i]) {
            cout << i << '\n';
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
