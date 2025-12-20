#include <array>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <random>
#include <ratio>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

const int k = 26;

struct vertex {
    vertex *p = 0;
    array<vertex *, k> to{0};
    array<vertex *, k> _go{0};
    vertex *_link = 0;
    int c = 0;
    bool term = false;

    bool root() {
        return p == 0;
    }

    vertex *add(int child) {
        auto &v = to[child];
        if (v == 0) {
            v = new vertex();
            v->p = this;
            v->c = child;
        }
        return v;
    }

    vertex *add(int *children, int n) {
        if (n == 0) {
            term = true;
            return this;
        }
        return add(children[0])->add(children + 1, n - 1);
    }

    vertex *add(char *children, int n) {
        if (n == 0) {
            term = true;
            return this;
        }
        return add(children[0] - 'a')->add(children + 1, n - 1);
    }

    vertex *link() {
        auto &l = _link;
        if (l == 0) {
            if (root()) {
                l = this;
            } else if (p->root()) {
                l = p;
            } else {
                l = p->link()->go(c);
            }
        }
        return l;
    }

    vertex *go(int ch) {
        auto &g = _go[ch];
        if (g == 0) {
            if (to[ch]) {
                g = to[ch];
            } else if (root()) {
                g = this;
            } else {
                g = link()->go(ch);
            }
        }
        return g;
    }

    vertex *go(char ch) {
        return go(ch - 'a');
    }

    void search(char *ch, int n, vector<vertex *> &ans) {
        // print(cout);
        // cout << '\n';
        if (term) {
            ans.push_back(this);
        }
        if (n == 0) {
            return;
        }
        go(ch[0])->search(ch + 1, n - 1, ans);
    }

    void print(ostream &s) {
        if (root()) {
            return;
        }
        p->print(s);
        s << (char)((term ? 'A' : 'a') + c);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t;
    cin >> t;
    int n;
    cin >> n;
    string s;
    vertex root;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        root.add(s.data(), s.size());
    }
    vector<vertex *> ans;
    int rnd = 0;
    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < t.size(); ++j) {
            t[j] = 'a' + (rnd % k);
        }
        rnd += 1337;
        root.search(t.data(), t.size(), ans);
        cout << ans.size() << '\n';
        ans.clear();
    }
}
