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
    cout << ' ';
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << min({(n / m) * b + (n % m) * a, (n / m + 1) * b, n * a});
}
