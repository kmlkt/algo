#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <vector>
using namespace std;

double C;

bool check(float x) {
    return x * x + sqrt(x) <= C;
}

int main() {
    cin >> C;
    double l = 1; // check(l) = true
    double r = C; // check(r) = false
    const double eps = 1e-7;
    while (r - l > eps) {
        double m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << fixed << setprecision(6) << l;
}
