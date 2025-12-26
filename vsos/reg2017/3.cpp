#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

struct worker {
    int i;
    int t;
    int a;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<worker> w(n);
    map<int, set<int>> bytime;
    for (int i = 0; i < n; ++i) {
        auto &wi = w[i];
        wi.i = i;
        cin >> wi.t >> wi.a;
        bytime[wi.t].insert(i);
    }
    map<int, set<int>> waiting;
    int pos = 0;
    int target = 0;
    int time = 0;
    for (int t = 0; true; ++t) {
        int dt = 1;
        if (pos == target) {
            if (target == 0) {
                if (waiting.size() > 0) {
                }
            }
        } else {
            if (target < pos) {
                pos = max(target, pos - dt);
            } else {
                pos = min(target, pos + dt);
            }
        }
    }
}
