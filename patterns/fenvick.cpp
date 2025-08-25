#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

vector a{2, 3, 4, 5, 1, 2, 3, 1, -1, 4};
vector<int> table;

int max_2(int x) {
    return (x & (~(x - 1)));
}

int sum(int r) {
    int ans = 0;
    while (r > 0) {
        ans += table[r - 1];
        r -= max_2(r);
    }
    return ans;
}

int sum(int l, int r) {
    return sum(r) - sum(l - 1);
}

void set(int i, int v) {
    int delta = v - sum(i, i);
    for (auto j = i; j <= table.size(); j += max_2(j)) {
        table[j - 1] += delta;
    }
}

int main() {
    auto n = a.size();
    auto height = (int)ceil(log2(n));
    table.resize(n);
    for (auto i = 1; i <= n; ++i) {
        table[i - 1] = a[i - 1];
        auto j = i - 1;
        for (auto k = 0; k < log2(max_2(i)); ++k) {
            table[i - 1] += table[j - 1];
            j -= 1 << k;
        }
    }
    for (auto i = 1; i <= n; ++i) {
        cout << table[i - 1] << ' ';
    }
    cout << endl;
    cout << sum(7, 8) << endl;
    cout << sum(8, 8) << endl;
    cout << sum(8, 9) << endl;
    cout << sum(8, 10) << endl;
    set(8, 3);
    cout << sum(7, 8) << endl;
    cout << sum(8, 8) << endl;
    cout << sum(8, 9) << endl;
    cout << sum(8, 10) << endl;
}
