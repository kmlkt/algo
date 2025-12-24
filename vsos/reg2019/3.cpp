#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

struct Node {
    int v;
    int size, prior;
    Node *l = 0, *r = 0;
    Node(int v) : v(v), size(1), prior(rand()) {}
};

int size(Node *n) {
    if (n == 0) {
        return 0;
    }
    return n->size;
}

void update(Node *n) {
    n->size = 1 + size(n->l) + size(n->r);
}

Node *merge(Node *l, Node *r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (l->prior > r->prior) {
        l->r = merge(l->r, r);
        update(l);
        return l;
    } else {
        r->l = merge(l, r->l);
        update(r);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int x) {
    if (!p) {
        return {0, 0};
    }
    if (size(p->l) + 1 <= x) {
        auto [l, r] = split(p->r, x - size(p->l) - 1);
        p->r = l;
        update(p);
        return {p, r};
    } else {
        auto [l, r] = split(p->l, x);
        p->l = r;
        update(p);
        return {l, p};
    }
}
Node *root = 0;
void insert(int pos, int v) {
    auto [l, r] = split(root, pos);
    auto n = new Node(v);
    root = merge(merge(l, n), r);
}

Node *cut(int pos) {
    auto [l, r] = split(root, pos + 1);
    auto [lol, lor] = split(l, pos);
    root = merge(lol, r);
    return lor;
}

Node *find(int pos) {
    auto [l, r] = split(root, pos + 1);
    auto [lol, lor] = split(l, pos);
    root = merge(merge(lol, lor), r);
    return lor;
}

int main() {
    int m, n;
    cin >> n >> m;
    vector<int> a(m);
    for (int &ai : a) {
        cin >> ai;
    }
    for (int j = 0; j < n; ++j) {
        int bj;
        cin >> bj;
        insert(j, bj);
    }
    map<int, int> nextM;
    vector<int> nextV(m, INT32_MAX);
    for (int i = m - 1; i >= 0; --i) {
        int &ai = a[i];
        if (nextM.find(ai) != nextM.end()) {
            nextV[i] = nextM[ai];
        }
        nextM[ai] = i;
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int &ai = a[i];
        int bj = -1;
        nextM[ai] = nextV[i];
        cout << "looking for " << ai << '\n';
        while (bj != ai) {
            for (int k = 0; k < n; ++k) {
                cout << find(k)->v << ' ';
            }
            cout << ": ";
            bj = cut(0)->v;
            if (nextM.find(bj) == nextM.end()) {
                nextM[bj] = INT32_MAX;
            }
            cout << bj << ' ' << nextM[bj] << '\n';
            int pos = min(nextM[bj] - i, n);
            if (ai != bj) {
                // pos = max(pos, 2);
            }
            ans.push_back(pos);
            insert(pos, bj);
        }
        cout << "----\n";
    }
    cout << ans.size() << '\n';
    for (int &ansi : ans) {
        cout << (ansi + 1) << ' ';
    }
}
