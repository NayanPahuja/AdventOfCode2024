#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H = 140;
  vector<string> a(H);
  for(auto &v : a) cin >> v;
  int W = (int) a[0].length();
  
  auto isValid = [&](int r, int c) {
    return (0 <= r && r < H && 0 <= c && c < W);
  };
  int ans = 0;
  const string temp = "XMAS";
  for (int row = 0; row < H; row++) {
    for(int col = 0; col < W; col++) {
      if(a[row][col] == 'X') {
        for(int nRow = -1; nRow <=1; nRow++) {
          for(int nCol = -1; nCol <=1; nCol++) {
            if(nRow == 0 && nCol == 0) continue;
            bool allOk = true;
            for(int i = 0; i < 4; i++) {
              int r2 = row + nRow*i;
              int c2 = col + nCol*i;
              if (isValid(r2,c2) && a[r2][c2] == temp[i]) {
              }
              else {
                allOk = false;
                break;
              }
            }
            ans += allOk;
          }
        }
      }
    }
  }
  printf("%d\n",ans);
}

int main() {
  solve();
  return 0;
} 
