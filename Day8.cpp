/*---------------------------------------*/
/*---------AUTHOR: NAYAN PAHUJA----------*/
/*---------------------------------------*/

#include <bits/stdc++.h>
typedef long long ll;
#define ilp(i,m,n) for (ll i=m;i<=n;i++)
#define dlp(i,m,n) for (ll i=m;i>=n;i--)
#define trv(i,vt) for (auto i:vt)
#define pll pair<ll,ll>
#define vec vector<ll>
#define vecpr vector<pll>
#define F first
#define S second
#define pb push_back
using namespace std;
const ll N=1e6+5,mod=1e9+7;

bool customSort(pair<ll,ll> &a, pair<ll,ll> &b){
    return a.second > b.second;
}

char a[1005][1005];

void solve() {
  int H = 50;
  int W = -1;
  vector<pair<int,int>> loc[256];
  for(int row = 0; scanf(" %s", a[row]) != EOF; row++) {
    W = strlen(a[row]);
    for (int col = 0; col < W; col++) {
      if (a[row][col] != '.') {
      loc[(int)a[row][col]].emplace_back(row,col);
      }
    }
  }
  set<pair<int,int>> st;

  auto inBounds = [&](int row, int col) {
    return (0 <= row && row < H && 0 <= col && col < W);
  };

  for (int x = 0; x < 256; x++) {
    const auto &v = loc[x];
    for (int i = 0; i < (int) v.size(); i++) {
      for (int j = 0; j < (int) v.size(); j++) {
        if (i == j) continue;
        int r1 = v[i].first;
        int c1 = v[i].second;
        int r2 = v[j].first;
        int c2 = v[j].second;
        int row = (r2) + (r2-r1);
        int col = (c2) + (c2-c1);
        if (inBounds(row,col)) {
          st.insert({row,col});
        }
      }
    }
  }

  cout << st.size() << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

