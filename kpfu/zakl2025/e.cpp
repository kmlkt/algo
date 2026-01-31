#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

const ll INF = 1e15;

struct vertex;

struct road {
    vertex *v, *u;
    ll w, b;
    ll sD = INF, fD = INF;
    bool operator<(road other) {
        return b < other.b;
    }
};

struct vertex {
    vector<road *> to;
    vector<road *> p;
    vector<ll> mnsD;
    vector<ll> mnfD;
    ll sD = INF, fD = INF;
};

void dfsS(road *r) {
    vertex *v = r->u;
    for (road *to : v->to) {
        if (to->b >= r->b && to->sD > r->sD + to->w) {
            to->sD = r->sD + to->w;
            dfsS(to);
        }
    }
}

void dfsF(road *r) {
    vertex *v = r->v;
    for (road *to : v->p) {
        if (to->b <= r->b && to->fD > r->fD + to->w) {
            to->fD = r->fD + to->w;
            dfsF(to);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vertex> V(n);
    vector<road> R(m);
    vertex *s = &V[0];
    vertex *f = &V[n - 1];
    for (road &r : R) {
        int v, u;
        cin >> v >> u >> r.w >> r.b;
        --v;
        --u;
        r.v = &V[v];
        r.u = &V[u];
        r.v->to.push_back(&r);
        r.u->p.push_back(&r);
    }
    for (road *r : s->to) {
        r->sD = r->w;
    }
    for (road *r : s->to) {
        dfsS(r);
    }
    for (road *r : f->p) {
        r->fD = r->w;
    }
    for (road *r : f->p) {
        dfsF(r);
    }
    for (vertex &v : V) {
        for (road *r : v.p) {
            v.sD = min(v.sD, r->sD);
        }
        for (road *r : v.to) {
            v.fD = min(v.fD, r->fD);
        }
    }

    for (vertex &v : V) {
        sort(v.p.begin(), v.p.end());
        int l = v.p.size();
        if (l == 0) {
            continue;
        }
        v.mnsD.resize(l);
        v.mnsD[0] = v.p[0]->sD;
        for (int i = 1; i < l; ++i) {
            v.mnsD[i] = min(v.mnsD[i - 1], v.p[i]->sD);
        }
    }
    for (vertex &v : V) {
        sort(v.to.begin(), v.to.end());
        int l = v.to.size();
        if (l == 0) {
            continue;
        }
        v.mnfD.resize(l);
        v.mnfD[l - 1] = v.to[l - 1]->fD;
        for (int i = l - 2; i >= 0; --i) {
            v.mnfD[i] = min(v.mnfD[i + 1], v.to[i]->fD);
        }
    }

    ll baseDist = s->fD;
    int ans = 0;
    ll bestDist = baseDist;
    for (road &r : R) {
        ll dist = INF;
        if (r.v == s) {
            for (road *next : r.u->to) {
                if (next->fD == INF) {
                    continue;
                }
                dist = min(dist, r.w + next->fD);
            }
        } else if (r.u == f) {
            for (road *prev : r.v->p) {
                if (prev->sD == INF) {
                    continue;
                }
                dist = min(dist, r.w + prev->sD);
            }
        } else {
            for (road *prev : r.v->p) {
                if (prev->sD == INF) {
                    continue;
                }
                int nextI = upper_bound(r.u->to.begin(), r.u->to.end(), prev) - r.u->to.begin();
                if (nextI >= r.u->to.size()) {
                    continue;
                }
                road *next = r.u->to[nextI];
                if (next->b >= prev->b) {
                    dist = min(dist, prev->sD + r.w + r.u->mnfD[nextI]);
                    ++ans;
                }
            }
        }
        if (dist < baseDist) {
            ++ans;
        }
        bestDist = min(bestDist, dist);
    }
    if (bestDist == INF) {
        bestDist = -1;
    }
    cout << ans << ' ' << bestDist;
}
