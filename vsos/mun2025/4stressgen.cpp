#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    fstream f("input.txt");
    int n = 200'000;
    f << n << '\n';
    for (int i = 0; i < n; ++i) {
        f << rand() % 1'000'000'000 << '\n';
    }
}
