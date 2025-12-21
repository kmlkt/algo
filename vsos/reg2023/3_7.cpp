#include <algorithm>
#include <cstdint>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

// O(n)
ll sum(int mask, int *a, int n) {
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
            ans += a[i];
        }
    }
    return ans;
}

// O(2^n * n)
void possible_sums(int *a, int n, ll *ans) {
    int cnt = (1 << n);
    for (int mask = 0; mask < cnt; ++mask) {
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        ans[mask] = sum(mask, a, n);
    }
    for (int i = 0; i < cnt; ++i) {
        cout << ans[i] << '\n';
    }
}

// O(log(n))
int find(ll *a, int n, ll x) {
    if (n == 1) {
        return a[0];
    }
    int m = n / 2;
    if (x < a[m]) {
        return find(a, m, x);
    } else {
        return find(a + m, n - m, x);
    }
}

// O(n log(n))
pair<int, int> find(ll *a, int n, ll *b, int l, ll x) {
    for (int i = 0; i < n; ++i) {
        int d = x - a[i];
        if (d < 0) {
            continue;
        }
        if (find(b, l, d) == d) {
            return {a[i], d};
        }
    }
    return {-1, -1};
}

ll sumsl[512], sumsr[512], sumsr_s[512];

// O(2^(n / 2) * n)
int find_sum(int *a, int n, ll x) {
    int half1 = n / 2;
    int half2 = n - half1;
    possible_sums(a, half1, sumsl);
    possible_sums(a + half1, half2, sumsr);
    int szl = 1 << half1;
    int szr = 1 << half2;
    partial_sort_copy(sumsr, sumsr + szr, sumsr_s, sumsr_s + szr);
    auto s = find(sumsl, szl, sumsr_s, szr, x);
    if (s.first == -1) {
        return -1;
    }
    int maskl = 0, maskr = 0;
    for (; maskl < szl; ++maskl) {
        if (sumsl[maskl] == s.first) {
            break;
        }
    }
    for (; maskr < szr; ++maskr) {
        if (sumsr[maskr] == s.second) {
            break;
        }
    }
    return maskl + (maskr << (half1));
}

// O(2^n * m * 2^(m/2) * m) = O(2^(n + m/2) * m^2)
pair<int, int> find_sum(vector<vector<int>> &a, ll x) {
    int n = a.size();
    int m = a[0].size(); /*
     int sum = 0;
     for (int i = 0; i < n; ++i) {
         for (int j = 0; j < m; ++j) {

         }
     } */
    int lim = (1 << n);
    vector<int> b(m);
    for (int maskh = 0; maskh < lim; ++maskh) {
        fill(b.begin(), b.end(), 0);
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            if (maskh & (1 << i)) {
                for (int j = 0; j < m; ++j) {
                    b[j] += a[i][j];
                    s += a[i][j];
                }
            }
        }
        if (s < x) {
            continue;
        }
        int maskw = find_sum(&b[0], m, x);
        if (maskw == -1) {
            continue;
        }
        return {maskh, maskw};
    }
    return {-1, -1};
}

void mask_to_array(int mask, int n, vector<int> &ans) {
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i))) {
            ans.push_back(i);
        }
    }
}

void answer(int maskh, int maskw, int h, int w) {
    if (maskh == -1 || maskw == -1) {
        cout << "NO";
    } else {
        cout << "YES\n";
        vector<int> ans;
        mask_to_array(maskh, h, ans);
        int rows = ans.size();
        mask_to_array(maskw, w, ans);
        cout << ans.size() << '\n';
        for (int i = 0; i < rows; ++i) {
            cout << "1 " << (ans[i] + 1) << '\n';
        }
        for (int i = rows; i < ans.size(); ++i) {
            cout << "2 " << (ans[i] + 1) << '\n';
        }
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    // h = 1;
    ll sum = 0;
    vector<vector<int>> a(h, vector<int>(w));
    for (auto &r : a) {
        for (auto &c : r) {
            cin >> c;
            sum += c;
        }
    }
    ll s;
    cin >> s;
    auto ans = find_sum(a, s);
    answer(ans.first, ans.second, h, w);
}
