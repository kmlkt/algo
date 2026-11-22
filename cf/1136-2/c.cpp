#include <algorithm>
#include <cmath>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;


void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &ai : a) {
        cin >> ai;
    }
    for(int &ai : a) {
        ai = (ai + x - 1) / x;
    }
    sort(a.begin(), a.end());
    a.pop_back();
    int damage = 0;
    int zakl = 0;
    for(int &ai : a) {
        zakl += max(0, ai - damage - 1);
        damage = max(damage + 1, ai);
    }
    cout << zakl << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
