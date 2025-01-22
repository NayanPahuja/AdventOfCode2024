#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

int main() {
  int H = 130, W = 130;
  vector<string> a(H);
  for (int i = 0; i < H; i++) cin >> a[i];
  
  auto isBounds = [&](int x, int y) {
    return (0 <= x && x < H && 0 <= y && y < W);
  };

  pair<int,int> originalStart(-1,-1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '^') {
        originalStart = {i,j};
        a[i][j] = '.';
      }
    }
  }


  int ans = 0;

  auto isCycle = [&]() {
    auto start = originalStart;
    int dir = 0;
    int turns = 0;
    while (true) {
      turns++;
      if(turns >= (W*H)+1) return true;
      int nx = start.first + dirs[dir].first;
      int ny = start.second + dirs[dir].second;
      if (!isBounds(nx,ny)) {
        return false;
      }
      if (a[nx][ny] == '#') {
        dir = (dir+1)%4;
      } else {
        start = {nx,ny};
      }
    } 
  };


  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] == '.' && originalStart != make_pair(i,j)) {
        a[i][j] = '#';
        if (isCycle()) {
          ans++;
        }
        a[i][j] = '.';
      }
    }
  }


  
  //set<pair<int,int>> vis;
  
  cout << ans << '\n';
  return 0;
}
