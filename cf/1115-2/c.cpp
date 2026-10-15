#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
using ll = long long;

struct Node {
    Node *p = 0;
    Node *l = 0;
    Node *r = 0;
    int x;
    int size;
    ll sum;
    int y = rand();

    Node(int x) : x(x), size(1), sum(x) {}

    void setl(Node *ln) {
        if (l) {
            l->p = 0;
        }
        l = ln;
        if (l) {
            l->p = this;
        }
        recalc();
    }
    void setr(Node *rn) {
        if (r) {
            r->p = 0;
        }
        r = rn;
        if (r) {
            r->p = this;
        }
        recalc();
    }

    void recalc();
};

int n_size(Node *n) {
    return n ? n->size : 0;
}

ll n_sum(Node *n) {
    return n ? n->sum : 0;
}

void Node::recalc() {
    size = n_size(l) + 1 + n_size(r);
    sum = n_sum(l) + x + n_sum(r);
    if (p) {
        p->recalc();
    }
}

Node *merge(Node *l, Node *r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (l->y < r->y) {
        l->setr(merge(l->r, r));
        return l;
    } else {
        r->setl(merge(l, r->l));
        return r;
    }
}

pair<Node *, Node *> split(Node *n, int x) {
    if (!n) {
        return {0, 0};
    }
    if (n->x <= x) {
        auto [l, r] = split(n->r, x);
        n->setr(l);
        return {n, r};
    } else {
        auto [l, r] = split(n->l, x);
        n->setl(r);
        return {l, n};
    }
}

pair<Node *, Node *> split_size(Node *n, int size) {
    if (!n) {
        return {0, 0};
    }
    if (n_size(n->l) < size) {
        auto [l, r] = split_size(n->r, size - n_size(n->l) - 1);
        n->setr(l);
        return {n, r};
    } else {
        auto [l, r] = split_size(n->l, size);
        n->setl(r);
        return {l, n};
    }
}

Node *root;
vector<Node> world;

void insert(int x) {
    auto [l, r] = split(root, x);
    root = merge(merge(l, new Node(x)), r);
}

void print(Node *n, int padding = 0) {
    if (!n) {
        return;
    }
    print(n->l, padding + 1);
    for (int i = 0; i < padding; ++i) {
        cout << ' ';
    }
    cout << n->x << " |" << n->size << '|' << " sum = " << n->sum << '\n';
    print(n->r, padding + 1);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> u(n);
    for (int &ui : u) {
        cin >> ui;
    }
    vector<int> umin(n);
    umin[0] = u[0];
    for (int i = 1; i < n; ++i) {
        umin[i] = min(umin[i - 1], u[i]);
    }

    vector<vector<int>> a(n, vector<int>(m));
    for (auto &ai : a) {
        for (auto &aij : ai) {
            cin >> aij;
        }
    }

    int bs_l = 0;
    int bs_r = m;

    while (bs_l < bs_r - 1) {
        int k = (bs_l + bs_r) / 2;
        root = 0;
        bool ok = 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int aij : a[i]) {
                insert(aij);
            }
            auto [ct_l, ct_r] = split_size(root, n_size(root) - k);
            int sum = n_sum(ct_r);
            if (sum >= umin[i]) {
                ok = 1;
                break;
            }
            root = ct_r;
            // print(root);
            // cout << "\n\n";
        }
        if (ok) {
            bs_r = k;
        } else {
            bs_l = k;
        }
    }
    cout << bs_r << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
