#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
vector<bool> used_total;
vector<int> ans;

bool dfs(int v) {
    if (used[v]) {
        return false;
    }
    if (used_total[v]) {
        return true;
    }
    used[v] = true;
    used_total[v] = true;
    for (int u : g[v]) {
        if (!dfs(u)) {
            return false;
        }
    }
    ans.push_back(v);
    return true;
}

vector<string> solve(vector<pair<int, int>> dependencies) {
    for (auto p : dependencies) {
        int v = p.first;
        int u = p.second;
        g.resize(max({(int)g.size(), v, u}));
        if (u == -1) {
            continue;
        }
        --v;
        --u;
        g[u].push_back(v);
    }
    used.resize(g.size());
    used_total.resize(g.size());
    bool ok = true;
    for (int i = 0; i < g.size(); ++i) {
        if (used_total[i]) {
            continue;
        }
        if (!dfs(i)) {
            ok = false;
            break;
        }
        fill(used.begin(), used.end(), false);
    }
    reverse(ans.begin(), ans.end());
    if (!ok) {
        return {"IMPOSSIBLE"};
    } else {
        string s = "";
        for (int v : ans) {
            s += to_string(v + 1) + " ";
        }
        return {"POSSIBLE", s};
    }
    return {};
}

int main() {
    int n;
    string line;
    getline(cin, line);
    n = stoi(line);

    vector<pair<int, int>> dependencies;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        stringstream ss(line);
        int jobId, dependsOn;
        ss >> jobId >> dependsOn;
        dependencies.push_back({jobId, dependsOn});
    }

    vector<string> result = solve(dependencies);
    for (const string &output : result) {
        cout << output << endl;
    }

    return 0;
}
