#include <algorithm>
#include <ios>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1;
        return 0;
    }
    int a = (3 - (n % 3)) % 3;
    for (int i = 0; i < a; ++i) {
        cout << '5';
    }
    for (int i = a; i < n; ++i) {
        cout << '1';
    }
}
