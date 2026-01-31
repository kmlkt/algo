#include "testlib.h"
#include <iostream>

using namespace std;

const int LIM = 1e9;

int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    int n = opt<int>(1);
    int m = opt<int>(2);
    cout << n << ' ' << m << '\n';
    for (int i = 0; i < n; ++i) {
        cout << rnd.next(0, LIM) << ' ';
    }
    cout << '\n';
    for (int i = 0; i < m; ++i) {
        cout << rnd.next(0, LIM) << ' ';
    }
}
