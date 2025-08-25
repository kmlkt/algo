#include <array>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int INF = 1'000'000'000;

struct point;

vector<string> a;
vector<vector<int>> dist;
vector<vector<point>> previous;

struct point {
    int x;
    int y;
    char &_a() {
        return a[y][x];
    }
    point valid_or_me(point another) {
        if (another.x < 0 || another.y < 0 || another.x >= a[0].size() || another.y >= a.size()) {
            return *this;
        }
        return another;
    }
    point r() {
        return valid_or_me({x + 1, y});
    }
    point l() {
        return valid_or_me({x - 1, y});
    }
    point t() {
        return valid_or_me({x, y + 1});
    }
    point b() {
        return valid_or_me({x, y - 1});
    }
    array<point, 4> neighbours() {
        return {t(), r(), l(), b()};
    }
    int &_dist() {
        return dist[y][x];
    }
    point &_previous() {
        return previous[y][x];
    }
    void print() {
        cout << x << ' ' << y << endl;
    }
};
stack<point> st;
void add_land(point p) {
    if (p._a() == '.') {
        st.push(p);
    }
}

point find_begin() {
    for (int y = 0; y < a.size(); ++y) {
        for (int x = 0; x < a[y].size(); ++x) {
            point p{x, y};
            if (p._a() == '.') {
                return p.b();
            }
        }
    }
    return {};
}

int main() {
    int h, w;
    cin >> h >> w;
    a.resize(h);
    dist.resize(h, vector<int>(w, INF));
    previous.resize(h, vector<point>(w));
    for (string &ai : a) {
        cin >> ai;
    }
    for (int y = 0; y < h; ++y) {
        add_land({0, y});
        add_land({(w - 1), y});
    }
    for (int x = 0; x < w; ++x) {
        add_land({x, 0});
        add_land({x, (h - 1)});
    }
    while (!st.empty()) {
        point x = st.top();
        st.pop();
        x._a() = '*';
        for (point n : x.neighbours()) {
            if (n._a() == '.') {
                st.push(n);
            }
        }
    }
    for (string ai : a) {
        cout << ai << endl;
    }
    point b = find_begin();
    b._dist() = 0;
    st.push(b);
    while (!st.empty()) {
        point x = st.top();
        st.pop();
        cout << x.x << ' ' << x.y << endl;
        for (point n : x.neighbours()) {
            // cout << n.x << ' ' << n.y << endl;
            if (x.y == b.y && (n.y < x.y || n.x < x.x)) {
                continue;
            }
            if (n._a() == '#' && n._dist() > x._dist() + 1) {
                n._dist() = x._dist() + 1;
                n._previous() = x;
                st.push(n);
            }
        }
        if (x.x == b.x && x.y == b.y) {
            x._dist() = INF;
        }
    }
    vector<string> ans(h, string(w, '.'));
    b.print();
    b._previous().print();
    for (point x = b._previous(); x.x != b.x || x.y != b.y; x = x._previous()) {
        ans[x.y][x.x] = '#';
    }
    ans[b.y][b.x] = '#';
    for (string ai : ans) {
        cout << ai << endl;
    }
}
