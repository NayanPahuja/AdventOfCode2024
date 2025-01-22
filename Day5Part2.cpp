#include <bits/stdc++.h>
using namespace std;

map<int, unordered_set<int>> mp;  
void topo(int a, vector<int>& order, map<int,int> &in,const set<int> present) {
  order.push_back(a);
  for(auto b : mp[a]) {
    if(present.count(b)) {
      if (--in[b] == 0) {
        topo(b,order,in,present);  
      }
    }
  }
}

void solve() {
    int n = 1176;
    map<int,int> indegree;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int v = stoi(s.substr(0, 2));     
        int u = stoi(s.substr(3));       
        mp[v].insert(u);
        indegree[u]++;
    }

    int ans = 0;

    for (int i = 0; i < 200; i++) {
        string input;
        cin >> input;
        
        vector<int> tokens;
        string token;
        istringstream iss(input);
        while (getline(iss, token, ',')) {
            tokens.push_back(stoi(token));
        }
        
        bool isValid = true;
        set<int> present;
        for(int x : tokens) present.insert(x);
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

        if (!isValid) {
            vector<int> order;
            map<int,int> in = indegree;
            vector<int> starting;
            for(auto x : tokens) {
              if(in[x] == 0) {
                starting.push_back(x);
              }
            }
            for(int x : starting) {
              topo(x,order,in,present);
            }
            ans += order[order.size()/2];
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    return 0;
}


