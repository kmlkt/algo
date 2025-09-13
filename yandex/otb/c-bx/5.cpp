#include <algorithm>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
int total;
vector<vector<int>> polki;
vector<vector<int> *> polka_of;

void add(vector<int> *polka) {
    int sz = polka->size();
    if (sz == 0)
        return;
    auto top = (*polka)[sz - 1];
    if (polka_of[top] == nullptr) {
        polka_of[top] = polka;
    } else {
        auto pj = polka_of[top];
        pj->pop_back();
        polka->pop_back();
        --total;
        polka_of[top] = nullptr;
        add(polka);
        add(pj);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    polki.resize(m);
    polka_of.resize(n, nullptr);
    int begin = 0;
    for (int i = 0; i < m; ++i) {
        int l;
        cin >> l;
        int end = begin + l;
        polki[i] = vector<int>(a.begin() + begin, a.begin() + end);
        begin = end;
        for (auto &pij : polki[i]) {
            cin >> pij;
            --pij;
        }
    }
    total = n;
    for (auto &polka : polki) {
        add(&polka);
    }
    cout << (total == 0 ? "Yes" : "No");
}
