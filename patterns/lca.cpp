#include <cmath>
#include <iostream>
#include <map>
#include <ostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

typedef int meta_t;

struct node {
    int depth;
    meta_t meta;
    node *first_child;
    node *young_brother;
    node *parent;
    node *first_unhandled_child;
};

vector<pair<int, int>> edges{{1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}, {6, 7}, {3, 8}};
vector<node> a;
map<meta_t, int> m;

vector<vector<node *>> table;

node *lca(meta_t f, meta_t t) {
    auto l = m[f];
    auto r = m[t];
    if (l > r) {
        swap(l, r);
    }
    r += 1;
    int dist = r - l;
    int lg2 = floor(log2(dist));
    int take = 1 << lg2;
    cout << "TAKE " << take << endl;
    int level = lg2;
    cout << "LEVEL " << level << endl;
    return min(table[level][l], table[level][r - take]);
}

int main() {
    auto n = 8;
    a = vector<node>(n);
    for (auto i = 0; i < n; ++i) {
        a[i].meta = i + 1;
    }
    for (auto e : edges) {
        auto f = e.first;
        auto t = e.second;
        --f;
        --t;
        if (a[f].first_child == nullptr) {
            a[f].first_child = &a[t];
            a[f].first_unhandled_child = &a[t];
        } else {
            auto big_brother = a[f].first_child;
            while (big_brother->young_brother != nullptr) {
                big_brother = big_brother->young_brother;
            }
            big_brother->young_brother = &a[t];
        }
        a[t].parent = &a[f];
    }

    stack<node *> st;
    st.push(&a[0]);
    vector<node *> survey;
    while (!st.empty()) {
        auto x = st.top();
        survey.push_back(x);
        if (x->first_unhandled_child == nullptr) {
            st.pop();
        } else {
            x->first_unhandled_child->depth = x->depth + 1;
            st.push(x->first_unhandled_child);
            x->first_unhandled_child = x->first_unhandled_child->young_brother;
        }
    }
    for (auto i = 0; i < survey.size(); ++i) {
        auto n = survey[i];
        m[n->meta] = i;
        cout << n->meta << ' ';
    }
    cout << endl;

    auto height = ceil(log2(survey.size()));
    table = vector<vector<node *>>(height + 1);
    table[0] = survey;
    for (auto i = 1; i <= height; ++i) {
        auto _2i = 1 << (i - 1);
        table[i] = vector<node *>(ceil(table[i - 1].size() - _2i));
        for (auto j = 0; j < table[i].size(); ++j) {
            table[i][j] = min(table[i - 1][j], table[i - 1][j + _2i]);
        }
    }
    for (auto i = 0; i <= height; ++i) {
        for (auto x : table[i]) {
            cout << x->meta << ' ';
        }
        cout << endl;
    }
    cout << lca(2, 2)->meta;
}
