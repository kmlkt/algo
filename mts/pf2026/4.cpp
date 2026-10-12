#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <array>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

map<int, int> cache;

int divide(int p, int q) {
    //cout << p / q << ',';
    while (q % 2 == 0) {
        q /= 2;
    }
    while(q % 5 == 0) {
        q /= 5;
    }
    if(cache.count(q) != 0) {
        return cache[q];
    }
    p %= q;
    p *= 10;
    map<int, int> pos;
    for(int i = 0; ; ++i) {
        //cout << p / q;
        p %= q;
        if(pos.count(p) != 0) {
            cache[q] = i - pos[p];
            return i - pos[p];
        }
        pos[p] = i;
        p *= 10;
    }
}


int divide_opt(int q) {
    while (q % 2 == 0) {
        q /= 2;
    }
    while(q % 5 == 0) {
        q /= 5;
    }
    ll drob = 9;
    for(int i = 1; i < q; ++i) {
        if(drob % q == 0) {
            return i;
        }
        drob = drob * 10 + 9;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // for(int i = 1; i < 100; ++i) {
    //     bool simple = true;
    //     for(int d = 2; d*d <= i; ++d) {
    //         if(i % d == 0) {
    //             simple = false;
    //             break;
    //         }
    //     }
    //     if(!simple) {
    //         continue;
    //     }
    //     cout << i << ":" << divide(1, i) << '\n';
    // }
    // return 0;
    ll p1, q1, p2, q2;
    cin >> p1 >> q1 >> p2 >> q2;
    ll ans_naive = 0;
    ll ans_opt = 0;
    for(int y = q1; y <= q2; ++y) {
        ll res_naive = 0;
        ll res_opt = 0;
        // for(int x = p1; x <= p2; ++x) {
        //     cout << x << '/' << y << '=';
        //     int sk = divide(x, y);
        //     cout << " (" << sk << ")\n";
        //     res_naive += sk;
        // }
        ll total = p2 - (p1 - 1);
        ll ynd = y;
        while (ynd % 2 == 0) {
            ynd /= 2;
        }
        while (ynd % 5 == 0) {
            ynd /= 5;
        }
        while (ynd % 3 == 0) {
            ynd /= 3;
        }
        ll crat = p2 / ynd - (p1 - 1) / ynd;
        ll noncrat_sk = divide(1, y);
        res_opt += crat + (total - crat) * noncrat_sk;
        // if(res_opt != res_naive) {
        //     cout << "\npizdec: " << res_opt << "!=" << res_naive << '\n';
        // }
        ans_naive += res_naive;
        ans_opt += res_opt;
        ans_opt %= MOD;
    }
    // cout << "\n" << ans_naive << '=';
    cout << ans_opt;
}
