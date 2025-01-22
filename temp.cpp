#include <bits/stdc++.h>
using namespace std;

// Adjacency list for the graph
map<int, unordered_set<int>> mp;

void topo(int node, vector<int>& order, map<int, int>& in, const set<int>& present) {
    order.push_back(node);
    for (int neighbor : mp[node]) {
        if (present.count(neighbor)) {
            if (--in[neighbor] == 0) {
                topo(neighbor, order, in, present);
            }
        }
    }
}

void solve() {
    int n = 21; // Number of edges
    map<int, int> indegree;

    // Read the graph edges
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int v = stoi(s.substr(0, 2));     // Start node
        int u = stoi(s.substr(3));       // End node
        mp[v].insert(u);
        indegree[u]++;
    }

    int ans = 0;

    // Process the 200 test cases
    for (int i = 0; i < 7; i++) {
        string input;
        cin >> input;
        if(input == "") continue;
        vector<int> tokens;
        string token;
        istringstream iss(input);
        while (getline(iss, token, ',')) {
            tokens.push_back(stoi(token));
        }

        // Check if the subset forms a valid sequence
        bool isValid = true;
        set<int> present(tokens.begin(), tokens.end());
        for (int u : tokens) {
            for (int v : tokens) {
                if (u != v && mp[u].count(v) == 0 && mp[v].count(u) > 0) {
                    isValid = false;
                    break;
                }
            }
            if (!isValid) break;
        }

        // If invalid, calculate median of topological order
        if (!isValid) {
            vector<int> order;
            map<int, int> in = indegree; // Clone indegree map for current tokens
            vector<int> starting;

            // Find starting points with indegree == 0 in the subset
            for (int x : tokens) {
                if (in[x] == 0) {
                    starting.push_back(x);
                }
            }

            // Perform topological sort
            for (int x : starting) {
                topo(x, order, in, present);
            }

            // Calculate the median
            ans += order[order.size() / 2];
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}

