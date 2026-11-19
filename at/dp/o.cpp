#include <algorithm>
#include <array>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int N = 1 << 21;
array<int, N> previ;
array<int, N> curr;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &ai : a) {
        for(int j = 0; j < n; ++j) {
            int aij;
            cin >> aij;
            ai |= (aij << j);
        }
    }

    int allFree = 0;
    for(int j = 0; j < n; ++j) {
        allFree <<= 1;
        allFree |= 1;
    }
    (previ)[allFree] = 1;
    for(int i = 0; i < n; ++i) {
        curr.fill(0);
        int woman = 1;
        for(int j = 0; j < n; ++j) {
            if(a[i] & woman) {
                for(int comb = 0; comb <= allFree; ++comb) {
                    if(comb & woman) {
                        curr[comb & ~woman] = (curr[comb & ~woman] + previ[comb]) % MOD;
                    }
                }
            }
            woman <<= 1;
        }
        swap(previ, curr);
    }
    cout << (previ)[0] << '\n';
}
