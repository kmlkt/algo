#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
const int NR = 2e3;
const int N = NR * NR;
const ll LIM = 4e12;
int main() {
    vector<bool> is_simple(N, true);
    is_simple[0] = false;
    is_simple[1] = false;
    for (int i = 2; i < NR; ++i) {
        if (!is_simple[i])
            continue;
        for (int j = i * 2; j < N; j += i) {
            is_simple[j] = false;
        }
    }
    int cnt = 0;
    vector<int> simple;
    for (int i = 0; i < N; ++i) {
        if (is_simple[i]) {
            simple.push_back(i);
        }
    }
    set<ll> ans;
    for (ll i = 0; i < simple.size() - 1; ++i) {
        for (ll j = i + 1; j < simple.size(); ++j) {
            ll x = simple[i] * simple[i] * simple[j] * simple[j];
            if (x > LIM || x < 0) {
                break;
            }
            if(x == 1) {
                cout << i << j;
            }
            ans.insert(x);
        }
    }
    for (int x : ans) {
        cout << x << ',';
    }
}
