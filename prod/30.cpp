
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct Review {
    string userId;
    string shopId;
    int rating;
    string text;
};

struct User {
    int reviewCount;
    int rating5Count;
    int minReviewLength;
    bool bot;
};

struct Shop {
    int reviewCount;
    int botCount;
};

vector<string> solve(const vector<Review> &reviews, int k, int m) {
    map<string, User> users;
    map<string, Shop> shops;
    for (auto r : reviews) {
        auto &u = users[r.userId];
        ++u.reviewCount;
        if (r.rating == 5) {
            ++u.rating5Count;
        }
        if (u.reviewCount == 1) {
            u.minReviewLength = r.text.size();
        } else {
            u.minReviewLength = min(u.minReviewLength, (int)r.text.size());
        }
    }
    for (auto &[_, u] : users) {
        if (u.reviewCount >= k ||
            u.minReviewLength < m ||
            u.reviewCount == u.rating5Count) {
            u.bot = true;
        }
    }
    for (auto r : reviews) {
        auto &u = users[r.userId];
        auto &s = shops[r.shopId];
        ++s.reviewCount;
        if (u.bot) {
            ++s.botCount;
        }
    }
    vector<string> ban;
    for (auto &[id, s] : shops) {
        if (s.botCount > s.reviewCount / 2) {
            ban.push_back(id);
        }
    }
    return ban;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m;
    cin >> n >> k >> m;
    string dummy;
    getline(cin, dummy);

    vector<Review> reviews;
    reviews.reserve(n);

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        size_t q1 = line.find('"');
        size_t q2 = line.rfind('"');

        string prefix = (q1 == string::npos) ? line : line.substr(0, q1);
        string text = (q1 != string::npos && q2 != string::npos && q2 > q1) ? line.substr(q1 + 1, q2 - q1 - 1) : "";

        istringstream iss(prefix);
        Review r;
        iss >> r.userId >> r.shopId >> r.rating;
        r.text = text;

        reviews.push_back(std::move(r));
    }

    auto offenders = solve(reviews, k, m);
    sort(offenders.begin(), offenders.end());

    if (offenders.empty()) {
        cout << "OK\n";
    } else {
        for (auto &id : offenders)
            cout << id << "\n";
    }
    return 0;
}
