#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll ops = 0;

template <ll b>
class ostnum {
  public:
    ll v;
    ostnum<b>(ll vv) {
        if (vv < 0) {
            vv = b - vv;
        }
        v = vv % b;
    }
    ostnum<b> operator+(ostnum<b> o) const {
        return ostnum<b>(v + o.v);
    }
    ostnum<b> operator-(ostnum<b> o) const {
        return ostnum<b>(v - o.v);
    }
    ostnum<b> operator*(ostnum<b> o) const {
        return ostnum<b>(v * o.v);
    }
    ostnum<b> pow(int p) const {
        ++ops;
        if (p == 0) {
            return ostnum<b>(1);
        } else if (p % 2 == 0) {
            auto rt = pow(p / 2);
            return rt * rt;
        } else {
            return (*this) * pow(p - 1);
        }
    }
};

int main() {
    ostnum<15> a(4);
    cout << a.pow(148'814'881).v << '\n';
    cout << ops;
}
