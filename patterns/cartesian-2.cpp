#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <iterator>

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
Node *root;
void insert(int pos, int v) {
    auto [l, r] = split(root, pos - 1);
    auto n = new Node(v);
    root = merge(merge(l, n), r);
}

Node *find(int pos) {
    auto [l, r] = split(root, pos);
    auto [lol, lor] = split(l, pos - 1);
    root = merge(merge(lol, lor), r);
    return lor;
}

int main() {
    root = 0;
    char cmd;
    int pos, v;
    while (cin >> cmd) {
        cin >> pos;
        if (cmd == '+') {
            cin >> v;
            insert(pos, v);
        } else if (cmd == '?') {
            auto n = find(pos);
            if (n == 0) {
                cout << "not found";
            } else {
                cout << n->v;
            }
            cout << '\n';
        }
    }
}
