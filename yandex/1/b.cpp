#include <array>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

const int LIM = 20'001;
const int DELTA = 10'000;

int main() {
    int n;
    cin >> n;
    array<int, LIM> cnt;
    cnt.fill(0);
    while (n--) {
        int ai;
        cin >> ai;
        ++cnt[ai + DELTA];
    }
    for (int i = 0; i < LIM; ++i) {
        for (int j = 0; j < cnt[i]; ++j) {
            cout << i - DELTA << ' ';
        }
    }
}
