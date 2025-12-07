#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
using namespace std;
double r;

double side(double alpha) {
    return 2 * r * r * (1 - cos(alpha));
}

double angle(double alpha, double beta) {
    double ans = abs(alpha - beta);
    if (ans > 180) {
        ans = 360 - ans;
    }
    return ans;
}

double side(double alpha, double beta) {
    return sqrt(2 * r * r * (1 - cos(angle(alpha, beta))));
}
double SS(double x, double y, double ang) {
    return x * y / 2 * sin(ang);
}

double S(double a, double b, double c) {
    double x = side(a, b);
    double y = side(b, c);
    double ang = angle(a, c) / 2;
    return SS(x, y, ang);
}

double eps = 1e-9;

double S(double a, double b, pair<double, double> c) {
    double l = c.first;
    double r = c.second;
    while (l < r - eps) {
        double diff = r - l;
        double m1 = l + diff / 3;
        double m2 = r - diff / 3;
        double s1 = S(a, b, m1);
        double s2 = S(a, b, m2);
        if (s1 < s2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return S(a, b, l);
}

double S(double a, pair<double, double> b, pair<double, double> c) {
    double l = b.first;
    double r = b.second;
    while (l < r - eps) {
        double diff = r - l;
        double m1 = l + diff / 3;
        double m2 = r - diff / 3;
        double s1 = S(a, m1, c);
        double s2 = S(a, m2, c);
        if (s1 < s2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return S(a, l, c);
}

double S(pair<double, double> a, pair<double, double> b, pair<double, double> c) {
    double l = a.first;
    double r = a.second;
    while (l < r - eps) {
        double diff = r - l;
        double m1 = l + diff / 3;
        double m2 = r - diff / 3;
        double s1 = S(m1, b, c);
        double s2 = S(m2, b, c);
        if (s1 < s2) {
            l = m1;
        } else {
            r = m2;
        }
    }
    return S(l, b, c);
}

const double PI = 3.1415926;

int main() {
    /*r = 5;
    double s = S({-PI / 6, PI / 6}, {2 * PI / 3 - PI / 6, 2 * PI / 3 + PI / 6}, {4 * PI / 3 - PI / 6, 4 * PI / 3 + PI / 6});
    cout << fixed << setprecision(7) << s;
    return 0;*/
    double a1, a2, b1, b2, c1, c2;
    cin >> r >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    double s = S({a1, a2}, {b1, b2}, {c1, c2});
    cout << fixed << setprecision(7) << s;
}
