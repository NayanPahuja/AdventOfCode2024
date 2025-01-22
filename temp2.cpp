#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Directions: Up, Right, Down, Left

void solve() {
    int m = 130, n = 130; // Matrix dimensions
    vector<vector<int>> mtrx(m, vector<int>(n, 0)); // Initialize the matrix with zeros.

    // Lambda to check if a position is within bounds
    auto inBounds = [&](int x, int y) {
        return (0 <= x && x < m && 0 <= y && y < n);
    };

    pair<int, int> startPos;

    // Input the matrix and identify the starting position
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char a;
            cin >> a;
            if (a == '.') 
                mtrx[i][j] = 0; // Empty cell
            else if (a == '#') 
                mtrx[i][j] = 2; // Obstacle
            else if (a == '^') {
                mtrx[i][j] = 1; // Start position is visited
                startPos = {i, j};
            }
        }
    }

    // Function to determine if placing an obstacle forms a cycle
    auto isCycle = [&](int sx, int sy) {
        int dirIdx = 0; // Start facing "Up"
        int x = sx, y = sy;
        set<pair<int, int>> visited; // To track visited positions
        int steps = 0;

        while (true) {
            steps++;
            if (steps > (m * n * 4)) return true; // Arbitrary upper bound for cycle detection

            int nx = x + dirs[dirIdx].first; // Calculate next row
            int ny = y + dirs[dirIdx].second; // Calculate next column

            if (!inBounds(nx, ny)) return false; // If out of bounds, no cycle

            if (mtrx[nx][ny] == 2) { 
                // Encounter obstacle: turn right
                dirIdx = (dirIdx + 1) % 4;
            } else {
                // Move to the next position
                if (visited.count({nx, ny})) return true; // If revisiting, it's a cycle
                visited.insert({nx, ny});
                x = nx;
                y = ny;
            }
        }
    };

    int ans = 0;

    // Iterate through each cell in the matrix
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            if (mtrx[row][col] == 0 && make_pair(row, col) != startPos) { 
                // Place obstacle temporarily
                mtrx[row][col] = 2;
                if (isCycle(startPos.first, startPos.second)) {
                    ans++; // Increment count if cycle is detected
                }
                // Remove the obstacle
                mtrx[row][col] = 0;
            }
        }
    }

    // Output the result
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
