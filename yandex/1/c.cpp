#include <array>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int LIM = 10'000'001;

int main() {
    int n;
    cin >> n;
    int mn = INT32_MAX;
    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
        mn = min(mn, ai);
    }
    vector<int> cnt(LIM);
    for (int ai : a) {
        ++cnt[ai - mn];
    }
    for (int i = 0; i < LIM; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << i + mn << ' ';
        }
    }
}
