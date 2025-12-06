#include <algorithm>
#include <cerrno>
#include <cinttypes>
#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>
using namespace std;

bool input() {
    char ans;
    cin >> ans;
    return ans == '1';
}

bool L() {
    cout << "L" << endl
         << endl;
    return input();
}

bool R() {
    cout << "R" << endl
         << endl;
    return input();
}

void S() {
    cout << "S" << endl
         << endl;
}

int check(int x) {
    for (int i = 0; i < x - 1; ++i) {
        if (R()) {
            S();
        }
    }
    if (!R()) {
        S();
    }
    for (int i = 0; i < x; ++i) {
        if (L()) {
            return i + 1;
        }
    }
    return -1;
}

void disable1() {
    R();
    if (L()) {
        S();
    }
}

int main() {
    disable1();
    int x = 1;
    int n = -1;
    while (n == -1) {
        n = check(x);
        x *= 10;
    }
    cout << n;
}
