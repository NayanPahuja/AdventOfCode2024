#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{-1,-1},{-1,1},{1,1},{1,-1}};


void solve() {
  cout << "H: " << '\n';
  int H;
  cin >> H;
  vector<string> a(H);
  for(auto &v : a) cin >> v;
  int W = (int) a[0].length();
  
 int ans = 0;
  for (int row = 1; row < H-1; row++) {
    for(int col = 1; col < W-1; col++) {
      if(a[row][col] == 'A') {
        string s;
        for(auto dir : dirs) {
          s += a[row+dir.first][col+dir.second];
        }
        if (s == "MMSS" || s == "SSMM" || s == "MSSM" || s == "SMMS") ans++;
      }
    }
  }
  printf("%d\n",ans);
}

int main() {
  solve();
  return 0;
} 

