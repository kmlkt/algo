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
array<bool, N> erat;
vector<int> prime;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int &ai : a) {
        cin >> ai;
    }
    for(int i = 0; i < n; ++i) {
        b[i] = *upper_bound(prime.begin(), prime.end(), a[i] - 1);
    }
    for(int &bi : b) {
        cout << bi << ' ';
    }
    cout << '\n';
}

int main() {
    for(int i = 2; i * i < N; ++i) {
        if(erat[i]){
            continue;
        }
        for(int j = i * 2; j < N; j += i) {
            erat[j] = 1;
        }
    }
    for(int i = 1; i < N; ++i) {
        if(!erat[i]) {
            prime.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
