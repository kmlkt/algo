#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <ios>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct block {
    int id;
    int size;
    bool filled;
};

int main() {
    int t, m;
    string cmd;
    cin >> t >> m;
    list<block> memory {block{0, m, 0}};
    int id = 1;
    while (t--) {
        cin >> cmd;
        if(cmd[0] == 'a') {
            int n;
            cin >> n;
            bool ok = 0;
            for(auto it = memory.begin(); it != memory.end(); ++it) {
                if(!it->filled && it->size >= n) {
                    it->id = id;
                    ++id;
                    it->filled = 1;
                    if(it->size > n) {
                        auto next = it;
                        ++next;
                        memory.insert(next, block{0, it->size - n, 0});
                        it->size = n;
                    }
                    cout << it->id << '\n';
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                cout << "NULL\n";
            }
        } else if(cmd[0] == 'e') {
            int x;
            cin >> x;
            if(x == 0) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
                continue;
            }
            bool ok = 0;
            for(auto it = memory.begin(); it != memory.end(); ++it) {
                if(it->id == x) {
                    it->id = 0;
                    it->filled = 0;
                    auto prev = it;
                    prev--;
                    if(it != memory.begin() && !prev->filled) {
                        prev->size += it->size;
                        memory.erase(it);
                        it = prev;
                    }
                    auto next = it;
                    next++;
                    if(next != memory.end() && !next->filled) {
                        it->size += next->size;
                        memory.erase(next);
                    }
                    ok = 1;
                    break;
                }
            }
            if(!ok) {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
            }
        } else {
            int freemem = 0;
            for(auto it = memory.begin(); it != memory.end(); ) {
                if(!it->filled) {
                    freemem += it->size;
                    it = memory.erase(it);
                } else {
                    ++it;
                }
            }
            if(freemem > 0) {
                memory.insert(memory.end(), block{0, freemem, 0});
            }
        }
    }
}
