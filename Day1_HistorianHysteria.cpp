#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;


void solve(){
  priority_queue<ll> pq1, pq2;
  for(int i = 0; i < 1000; i++){
    int a,b;
    cin >> a >> b;
    pq1.push(a);
    pq2.push(b);
  }
  int n = 1000;
  ll res = 0;
  while(n--){
    res += abs(pq1.top()-pq2.top());
    pq1.pop();
    pq2.pop();
  }
  cout << res << '\n';
}

int main() {
  solve();
  return 0;
}
