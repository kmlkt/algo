#include <algorithm>
#include <array>
#include <cinttypes>
#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
// Вычисления по модулю
struct mint {
  private:
    ll v = 0;

  public:
    mint() {}
    mint(ll v) : v(v % MOD + (v < 0) * MOD) {}
    mint(int v) : v(v % MOD + (v < 0) * MOD) {}
    mint operator+(const mint &other) const { return v + other.v; }
    mint operator-(const mint &other) const { return v - other.v; }
    mint operator*(const mint &other) const { return v * other.v; }
    mint operator/(const mint &other) const { return *this * other.inverse(); }
    mint pow(int p) const {
        mint res = 1;
        mint a = v;
        while (p != 0) {
            if (p & 1)
                res = res * a;
            a = a * a;
            p >>= 1;
        }
        return res;
    }
    mint inverse() const { return pow(MOD - 2); }
    static vector<mint> factorial_cache;
    static mint factorial(int n) {
        mint res = 1;
        for (int i = factorial_cache.size(); i <= n; ++i) {
            factorial_cache.push_back(factorial_cache.back() * i);
        }
        return factorial_cache[n];
    }
    explicit operator int() const { return v; }
    explicit operator ll() const { return v; }
};
vector<mint> mint::factorial_cache{1};
std::ostream &operator<<(std::ostream &os, const mint p) {
    os << (ll)p;
    return os;
}

mint c(int n, int k) {
    return (mint::factorial(n) / (mint::factorial(k) * mint::factorial(n - k)));
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << c(n + m - 1, m);
}
