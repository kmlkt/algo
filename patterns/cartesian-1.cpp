#include <cstdint>
#include <cstdlib>
#include <iostream>

using namespace std;
using ll = long long;

struct Node {
    int key, prior;
    Node *l = 0, *r = 0;
    Node(int key) : key(key), prior(rand()) {}
};

Node *merge(Node *l, Node *r) {
    if (!l) {
        return r;
    }
    if (!r) {
        return l;
    }
    if (l->prior > r->prior) {
        l->r = merge(l->l, r);
        return l;
    } else {
        r->l = merge(l, r->l);
        return r;
    }
}

pair<Node *, Node *> split(Node *p, int x) {
    if (!p) {
        return {0, 0};
    }
    if (p->key <= x) {
        auto [l, r] = split(p->r, x);
        p->r = l;
        return {p, r};
    } else {
        auto [l, r] = split(p->l, x);
        p->l = r;
        return {l, p};
    }
}
Node *root;
void insert(int x) {
    auto [l, r] = split(root, x);
    auto n = new Node(x);
    root = merge(merge(l, n), r);
}

bool find(int x) {
    auto [l, r] = split(root, x);
    auto [lol, lor] = split(l, x - 1);
    bool ans = lor != 0;
    merge(merge(lol, lor), r);
    return ans;
}

int main() {
    root = 0;
    char cmd;
    int x;
    while (cin >> cmd) {
        cin >> x;
        if (cmd == '+') {
            insert(x);
        } else if (cmd == '?') {
            cout << find(x) << '\n';
        }
    }
}
