#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int index, vector<ll>& vals, ll key, ll currVal) {
  if (index == vals.size()) return currVal == key;

  if (solve(index+1,vals,key,currVal + vals[index])) {
    return true;
  }
  if (solve(index+1,vals,key,currVal * vals[index])) {
    return true;
  }
  if (solve(index+1,vals,key,stoll(to_string(currVal) + to_string(vals[index])))) {
    return true;
  }
  return false;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll ans = 0;
  int H = 850;
  for (int i = 1; i <= H; i++) {
    string s;
    getline(cin, s);

    ll key = 0;
    size_t pos = s.find(':');
    if (pos == string::npos) {
      continue;
    }

    key = stoll(s.substr(0, pos));

    vector<ll> vals;
    stringstream ss(s.substr(pos + 1));
    ll val;
    while (ss >> val) {
      vals.push_back(val);
    }

    bool resp = solve(1,vals,key,vals[0]);
    if(resp) {
      ans += key;
    }
  }

  cout << ans << '\n';

  return 0;
}

