#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n = 21;
    map<int, unordered_set<int>> mp;  
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int v = stoi(s.substr(0, 2));     
        int u = stoi(s.substr(3));       
        mp[v].insert(u);                 
    }

    int ans = 0;

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

        bool isValid = true;
        for (int i = 0; i < tokens.size() && isValid; i++) {
            int u = tokens[i];
            for (int j = i + 1; j < tokens.size(); j++) {
                int v = tokens[j];
                if (mp[u].count(v) == 0 && mp[v].count(u) > 0) {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid) {
            ans += tokens[tokens.size() / 2];
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}

