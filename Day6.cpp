#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
    int m = 130, n = 130; 
    vector<vector<int>> mtrx(m, vector<int>(n, 0)); 
    auto inBounds = [&](int x, int y) {
        return (0 <= x && x < m && 0 <= y && y < n);
    };

    pair<int, int> startPos;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            if (a == '.') 
                mtrx[i][j] = 0;
            else if (a == '#') 
                mtrx[i][j] = 2;
            else if (a == '^') {
                mtrx[i][j] = 1;
                startPos = {i, j};
            }
        }
    }

    int dirIdx = 0;
    int x = startPos.first, y = startPos.second;

    while (true) {
        int nx = x + dirs[dirIdx].first; 
        int ny = y + dirs[dirIdx].second;
        if (!inBounds(nx, ny)) {
            break;
        }

        if (mtrx[nx][ny] == 2) {
            dirIdx = (dirIdx + 1) % 4;
        } else {
            x = nx;
            y = ny;
            mtrx[x][y] = 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mtrx[i][j] == 1) 
                ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
