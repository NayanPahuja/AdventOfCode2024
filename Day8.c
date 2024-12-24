#include <stdio.h>

char a[51][51];

int main() {
  int W = -1;
  int where[256][2];
  for (int row = 0; scanf(" %s", a[row] != EOF); row++) {
    W = strlen(a[row]);
    for (int col = 0; col < W; col++) {
      if (a[row][col] != '.') {
        where[(int)a[row][col]][0] = row;
        where[(int)a[row][col]][1] = col;
      }:
    }
  }
  return 0;
}
