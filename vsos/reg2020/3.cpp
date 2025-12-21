#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct answer {
    int pos;
    char c;
    int delta;
    bool operator<(answer other) const {
        return delta < other.delta;
    }
};

string gens = "ACGT";

char other(char a, char b = ' ') {
    for (char g : gens) {
        if (g != a && g != b) {
            return g;
        }
    }
    return ' ';
}

struct seq {
    int n = 0;
    int o = 0;
    char c = ' ';

    answer insert() {
        if (n == 1) {
            return {0, ' ', 0};
        }
        char i = other(c);
        if (n == 2) {
            return {o + 1, i, 1};
        }
        if (n == 3) {
            return {o + 1, i, 2};
        }
        return {o + 2, i, 3};
    }

    answer rem(seq &prev, seq &next) {
        if (n == 1) {
            if (prev.c == next.c) {
                int sum = prev.n + next.n;
                if (sum == 2) {
                    return {o, ' ', 1};
                }
                if (sum == 3) {
                    return {o, ' ', 2};
                }
                return {o, ' ', 3};
            }
            return {o, ' ', 1};
        }
        if (n == 2) {
            return {o, ' ', 1};
        }
        return {o, ' ', 0};
    }

    answer left(seq &prev) {
        char i = other(c, prev.c);
        return {o, i, 1};
    }

    answer optAdd(seq &prev) {
        return max(left(prev), insert());
    }
};

int main() {
    string s;
    cin >> s;
    vector<seq> a;
    seq cur;
    for (char c : s) {
        if ('0' <= c && c <= '9') {
            cur.n *= 10;
            cur.n += (c - '0');
        } else {
            cur.c = c;
            if (cur.n == 0) {
                cur.n = 1;
            }
            a.push_back(cur);
            cur.o += cur.n;
            cur.n = 0;
            cur.c = ' ';
        }
    }
}
