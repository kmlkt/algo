#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

struct song {
    string name;
    ll dlit;
};

struct delsong {
    string name;
    ll dlit;
    ll time;
};

template <class T>
T &last(vector<T> &v) {
    return v[v.size() - 1];
}

int main() {
    int n;
    cin >> n;
    vector<song> q(n);
    for (auto &s : q) {
        cin >> s.name >> s.dlit;
    }
    reverse(q.begin(), q.end());
    int m;
    cin >> m;
    vector<delsong> add(m);
    for (auto &s : add) {
        cin >> s.time >> s.name >> s.dlit;
    }
    sort(add.begin(), add.end(), [](delsong l, delsong r) { return l.time < r.time; });
    reverse(add.begin(), add.end());
    ll curTime = 0;
    while (!q.empty() || !add.empty()) {
        if (q.empty()) {
            curTime = last(add).time;
        }
        while (!add.empty() && curTime >= last(add).time) {
            auto l = last(add);
            q.push_back({l.name, l.dlit});
            add.pop_back();
        }
        cout << last(q).name << " " << curTime << "\n";
        curTime += last(q).dlit;
        q.pop_back();
    }
}
