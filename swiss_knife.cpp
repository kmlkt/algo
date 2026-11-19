#include <array>
#include <iostream>
#include <numeric>
#include <string>
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
    mint operator -() const {return mint() - *this;}
    friend bool operator==(mint a, mint b) {return a.v == b.v;}
    friend bool operator!=(mint a, mint b) {return a.v != b.v;}
    mint pow(int p) const {
        mint r = 1, a = *this;
        for (;p > 0;p >>= 1, a = a * a) if (p & 1) r = r * a;
        return r;
    }
    mint inv() const { return pow(MOD - 2); }
    friend ostream &operator<<(ostream &os, mint a) { return os << a.v; }
    friend istream &operator>>(istream &is, mint &a) { ll x; is >> x; a = x; return is;}
};

const int FAC_CNT = 1e5;
array<mint, FAC_CNT> FAC, INV_FAC;
void build_factorials() {
    FAC[0] = 1;
    for(int i = 0; i < FAC_CNT; ++i)
        FAC[i] = FAC[i - 1] * i;
    INV_FAC[FAC_CNT-1] = FAC[FAC_CNT-1].inv();
    for(int i = FAC_CNT-1; i > 0; --i) {
        INV_FAC[i-1] = INV_FAC[i] * i;
    }
}

struct rat {
    ll p = 0, q = 1;
    rat() {}
    rat(ll p, ll q) : p(p), q(q) {
        if(q < 0) {
            p = -p;
            q = -q;
        }
        ll g = gcd(p, q);
        p /= g;
        q /= q;
    }
    friend rat operator + (rat a, rat b) {return rat(a.p * b.q + b.p * a.q, b.q * a.q);}
    friend rat operator - (rat a, rat b) {return rat(a.p * b.q - b.p * a.q, b.q * a.q);}
    friend rat operator * (rat a, rat b) {return rat(a.p * b.p, b.q * a.q);}
    friend rat operator / (rat a, rat b) {return rat(a.p * b.q, b.p * a.q);}
    rat operator+=(const rat &o) { return *this = *this + o; }
    rat operator-=(const rat &o) { return *this = *this - o; }
    rat operator*=(const rat &o) { return *this = *this * o; }
    rat operator/=(const rat &o) { return *this = *this / o; }
    rat operator -() const{return rat(-p, q);}
    friend bool operator== (rat a, rat b) {return a.p == b.p && a.q == b.q;}
    friend bool operator!= (rat a, rat b) {return !(a == b);}
    rat inv() const { return rat(q, p); }
    friend ostream &operator<<(ostream &os, rat a) { return os << a.p << '/' << a.q; }
    friend istream &operator>>(istream &is, rat &a) { ll p, q; is >> p >> q; a = rat(p, q); return is;}
};

int bitceil(int x) {
    int p = 1;
    while(p < x) {
        p <<= 1;
    }
    return p;
}

int lsb(int x) {
    return x & -x;
}

struct fenvick {
    vector<int> t;
    fenvick(int n) : t(bitceil(n+1)) {}
    int sum (int r) {
        int res = 0;
        for (; r > 0; r -= lsb(r))
            res += t[r];
        return res;
    }

    int sum (int l, int r) {
        return sum(r) - sum(l-1);
    }
    void add (int k, int x) {
        for (; k < t.size(); k += lsb(k))
            t[k] += x;
    }
};

struct segtree_laaksonen {
    int n;
    vector<int> t;
    segtree_laaksonen(int n) : n(bitceil(n)), t(bitceil(n)*2) {}
    int sum(int a, int b) {
        a += n;
        b += n;
        int s = 0;
        while (a <= b) {
            if (a & 1)
                s += t[a++];
            if (!(b & 1))
                s += t[b--];
            a /= 2;
            b /= 2;
        }
        return s;
    }
    void add(int k, int x) {
        k += n;
        t[k] += x;
        for (k /= 2; k >= 1; k /= 2)
            t[k] = t[2 * k] + t[2 * k + 1];
    }
};

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++) {
        int cur = p[i - 1];
        while (s[i] != s[cur] && cur > 0)
            cur = p[cur - 1];
        if (s[i] == s[cur])
            p[i] = cur + 1;
    }
    return p;
}

vector<int> z_function(string &s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

vector<int> manacher_odd(string &s) {
    int n = (int) s.size();
    vector<int> d(n, 1);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
    return d;
}

vector<int> manacher_even(string &s) {
    int n = (int) s.size();
    vector<int> d(n, 0);
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
        if (i < r)
            d[i] = min(r - i, d[l + r - i - 1]);
        while (i - d[i] >= 0 && i + d[i] + 1 < n && s[i - d[i]] == s[i + d[i] + 1])
            d[i]++;
        if (i + d[i] > r)
            l = i - d[i] + 1, r = i + d[i];
    }
    return d;
}

mint string_hash(string &s) {
    const int k = 31; // k > размера алфавита
    mint h = 0, m = 1;
    for (char c : s) {
        int x = (c - 'a' + 1);
        h += m * x;
        m *= k;
    }
    return h;
}


bool isprime_miller_rabin(ll n) {
    using u64 = uint64_t;
    using u128 = __uint128_t;
    auto binpower = [](u64 base, u64 e, u64 mod) {
        u64 result = 1;
        base %= mod;
        while (e) {
            if (e & 1)
                result = (u128)result * base % mod;
            base = (u128)base * base % mod;
            e >>= 1;
        }
        return result;
    };
    auto check_composite = [&](u64 n, u64 a, u64 d, int s) {
        a %= n;
        if (a == 0) // n divides the base, so this base can say nothing about n
            return false;
        u64 x = binpower(a, d, n);
        if (x == 1 || x == n - 1)
            return false;
        for (int r = 1; r < s; r++) {
            x = (u128)x * x % n;
            if (x == n - 1)
                return false;
        }
        return true;
    };
    if (n < 2)
        return false;

    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (u64 a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
        if (check_composite(n, a, d, s))
            return false;
    return true;
}
