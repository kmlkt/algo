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

struct mint {
    ll v = 0;
    mint() {}
    mint(ll v) : v(v % MOD) {if(v < 0) v += MOD;}
    mint operator+=(const mint &o) { if(v += o.v > MOD) v -= MOD; return *this; }
    mint operator-=(const mint &o) { if(v -= o.v < 0) v += MOD; return *this; }
    mint operator*=(const mint &o) { return v = (v * o.v) % MOD; return *this; }
    mint operator/=(const mint &o) { return *this *= o.inv(); }
    friend mint operator + (mint a, mint b) {return a += b;}
    friend mint operator - (mint a, mint b) {return a -= b;}
    friend mint operator * (mint a, mint b) {return a *= b;}
    friend mint operator / (mint a, mint b) {return a /= b;}
    mint operator -() const{return mint() - *this;}
    friend bool operator== (mint a, mint b) {return a.v == b.v;}
    friend bool operator!= (mint a, mint b) {return a.v != b.v;}
    mint pow(int p) const {
        mint r = 1, a = *this;
        for (;p > 0;p >>= 1, a = a * a) if (p & 1) r = r * a;
        return r;
    }
    mint inv() const { return pow(MOD - 2); }
    friend ostream &operator<<(ostream &os, mint a) { return os << a.v; }
    friend istream &operator>>(istream &is, mint &a) { ll x; is >> x; a = x; return is;}
};

const int FAC_CNT = 1e6+1;
array<mint, FAC_CNT> FAC, INV_FAC;
void build_factorials() {
    FAC[0] = 1;
    for(int i = 1; i < FAC_CNT; ++i)
        FAC[i] = FAC[i - 1] * i;
    INV_FAC[FAC_CNT-1] = FAC[FAC_CNT-1].inv();
    for(int i = FAC_CNT-1; i > 0; --i) {
        INV_FAC[i-1] = INV_FAC[i] * i;
    }
}

mint C(int n, int k) {
    return FAC[n] * INV_FAC[k] * INV_FAC[n-k];
}

int main() {
    build_factorials();
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        cout << C(a, b) << '\n';
    }
}
