#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll win = 0;
        ll lose = 0;
        for (int j = 0; j < n; ++j) {
            int match;
            cin >> match;
            win += match / 10;
            lose += match % 10;
        }
        cout << win << ' ' << lose << '\n';
    }
}
