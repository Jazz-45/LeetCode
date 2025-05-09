class Solution {
public:
    bool solve(vector<vector<int>>& grid, int row, int col, int moveNo) {
        int n = grid.size();
        if (moveNo == n * n - 1)
            return true;
        int dx[] = {-2, -2, 2, 2, 1, 1, -1, -1};
        int dy[] = {-1, 1, -1, 1, 2, -2, 2, -2};

        for (int i = 0; i < 8; i++) {
            int newr = row + dx[i];
            int newc = col + dy[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < n) {
                if (grid[newr][newc] == moveNo + 1) {
                    if (solve(grid, newr, newc, moveNo + 1))
                        return true; // ✅ only return true if a valid path is
                                     // found
                }
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        return solve(grid, 0, 0, 0);
    }
};