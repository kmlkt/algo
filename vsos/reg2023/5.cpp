#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

int del(int x) {
    int ans = 0;
    int k = 2;
    while (k * k <= x) {
        if (x % k == 0) {
            x /= k;
            ++ans;
        } else {
            ++k;
        }
    }
    ++ans;
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }
    for (int ai : a) {
        cout << (del(ai) % 2 + 1) << ' ';
    }
}
