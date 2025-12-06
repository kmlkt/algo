#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
using ll = long long;

vector<int> step;

int main() {
    int n, m;
    cin >> n >> m;
    step.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ++step[u];
        ++step[v];
    }
    for (int s : step) {
        cout << s << ' ';
    }
}
