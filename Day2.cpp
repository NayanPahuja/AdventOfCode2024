#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n = 1000;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    vector<int> temp;
    while(true) {
      int a;
      scanf("%d",&a);
      temp.push_back(a);
      char c;
      scanf("%c",&c);
      if(c == '\n') break;
    }
      bool valid = true;
      bool inc = true;
      bool dec = true;
    for(int k = 0; k < temp.size()-1; k++) {
      int diff = temp[k+1] - temp[k];
      if(diff > 0) dec = false;
      if(diff < 0) inc = false;
      if(!(1 <= abs(diff) && abs(diff) <=3)) {
        valid = false;
        break;
      }
    }
    if(valid && (inc || dec)) ans++;
  }
  printf("%d\n",ans);
  return 0;
}
