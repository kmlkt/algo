#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int N = 100'101;
array<bool, N> compos;
vector<int> prime;

int gcd(int a, int b) {
    while(b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool can(int a, int b) {
    return gcd(a, b - a) == 1;
}

vector<int> brute_res;
bool brute(int a, int b, int k) {
    if(k == 1) {
        return can(a, b);
    }
    for(int t = a + 1; t < b; ++t) {
        if(can(a, t) && brute(t, b, k - 1)) {
            if(k == 2) {
                brute_res.push_back(b - t);
            }
            brute_res.push_back(t - a);
            return 1;
        }
    }
    return 0;
}

void solve() {
    int a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << '\n';
    }
    if(can(a, b)) {
        cout << 1 << '\n' << b - a << '\n';
        return;
    }

    for(auto p = upper_bound(prime.begin(), prime.end(), a); p < prime.end() && *p < b; ++p) {
        if(can(*p, b)) {
            cout << 2 << '\n' << *p - a << ' ' << b - *p << '\n';
            return;
        }
    }

    for(int k = 2; k <= 15; ++k) {
        if(brute(a, b, k)) {
            cout << k << '\n';
            reverse(brute_res.begin(), brute_res.end());
            for(int bi : brute_res) {
                cout << bi << ' ';
            }
            cout << '\n';
            brute_res.clear();
            return;
        }
    }
}

int main() {
    for(int i = 2; i * i < N; ++i) {
        if(compos[i]){
            continue;
        }
        for(int j = i * 2; j < N; j += i) {
            compos[j] = 1;
        }
    }
    for(int i = 1; i < N; ++i) {
        if(!compos[i]) {
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
