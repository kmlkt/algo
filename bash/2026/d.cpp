#include <ios>
#include <iostream>
#include <numeric>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

struct point {
    ll x, y;
};

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> distrib(0, 1'000'000'000);

    int n;
    cin >> n;
    vector<point> a(n);
    for (point &ai : a) {
        cin >> ai.x >> ai.y;
    }
    set<ll> distances;
    while (1) {
        ll x = distrib(gen);
        ll y = distrib(gen);
        bool ok = true;
        for (point &ai : a) {
            ll dist = (x - ai.x) * (x - ai.x) + (y - ai.y) * (y - ai.y);
            if (distances.count(dist)) {
                ok = false;
                break;
            }
            distances.insert(dist);
        }
        if (ok) {
            cout << x << ' ' << y;
            break;
        }
    }
}
