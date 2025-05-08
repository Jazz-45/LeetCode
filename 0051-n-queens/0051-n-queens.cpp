class Solution {
public:
    vector<vector<string>> ans;

    bool canPlace(int row, int col, int n, vector<string>& grid) {
        // Check vertically
        for (int i = row; i >= 0; i--) {
            if (grid[i][col] == 'Q') return false;
        }

        // Check left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') return false;
        }

        // Check right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') return false;
        }

        return true;
    }

    void nQueens(int n, int row, vector<string>& grid) {
        if (row == n) {
            ans.push_back(grid);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (canPlace(row, col, n, grid)) {
                grid[row][col] = 'Q';
                nQueens(n, row + 1, grid);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        nQueens(n, 0, grid);
        return ans;
    }
};
