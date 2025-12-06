#include <iostream>
using namespace std;

int x = 0;
int y = 0;

bool ask(int dx, int dy) {
    cout << "? " << dx << " " << dy << endl;
    char ans;
    cin >> ans;
    return ans == '+';
}

bool checkBL(int d) {
    bool ans = ask(-d, -d);
    if (ans) {
        x += d;
        y += d;
    }
    return ans;
}

bool checkBR(int d) {
    bool ans = ask(d, -d);
    if (ans) {
        y += d;
    }
    return ans;
}

bool checkTL(int d) {
    bool ans = ask(-d, d);
    if (ans) {
        x += d;
    }
    return ans;
}

void answer() {
    cout << "! " << (char)('a' + x) << (y + 1);
}

int main() {
    checkBL(4);
    checkBL(2);
    checkBL(1);
    if (x == 7) {
        answer();
        return 0;
    }
    if (checkBR(1)) {
        checkBR(4);
        checkBR(2);
        checkBR(1);
    } else {
        checkTL(4);
        checkTL(2);
        checkTL(1);
    }
    answer();
}
