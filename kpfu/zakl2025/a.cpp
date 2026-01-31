#include <cmath>
#include <iostream>
using namespace std;

const double PI = 3.1415926;

double k, l, a, x, r, s1;

int main() {
    cin >> k >> l;
    a = 2.0 * PI / k;
    x = l / k;
    r = x / sqrt(2.0 * (1.0 - cos(a)));
    s1 = r * r * sin(a) / 2.0;
    double ans = s1 * k;
    cout << ans;
}
