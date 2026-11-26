#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n;
    cin >> n;
    int n1 = n;
    deque<int> factor;
    for(int i = 2; i * i <= n1; ++i) {
        while (n1 % i == 0) {
            factor.push_back(i);
            n1 /= i;
        }
    }
    if(n1 > 1) {
        factor.push_back(n1);
    }
    if(factor.size() < 2) {
        cout << "NO\n";
        return;
    }
    int d1 = factor.front();
    factor.pop_front();
    int d2 = factor.front();
    factor.pop_front();
    if(d2 == d1) {
        if(factor.size() == 0) {
            cout << "NO\n";
            return;
        }
        d2 *= factor.front();
        factor.pop_front();
    }
    int d3 = n / d1 / d2;
    if(d3 == d1 || d3 == d2 || d3 == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << d1 << ' ' << d2 << ' ' << d3 << '\n';
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
