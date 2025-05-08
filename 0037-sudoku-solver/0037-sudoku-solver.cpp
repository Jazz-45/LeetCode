class Solution {
public:
    vector<unordered_set<char>> s; // 9 sub-boxes

    // Fill sub-box sets with existing digits
    void fillSubBox(vector<vector<char>>& board) {
        s.clear();
        s.resize(9, unordered_set<char>());

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int boxNo = (i / 3) * 3 + (j / 3);
                    s[boxNo].insert(board[i][j]);
                }
            }
        }
    }

    // Check if placing digit k at (row, col) is valid
    bool isSafe(vector<vector<char>>& board, int row, int col, int k) {
        char digit = k + '0';

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == digit) return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == digit) return false;
        }

        // Check sub-box
        int boxNo = (row / 3) * 3 + (col / 3);
        if (s[boxNo].find(digit) != s[boxNo].end()) return false;

        return true;
    }

    // Recursive solver
    bool solve(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // Solved entire board
        if (col == 9) return solve(board, row + 1, 0); // Move to next row

        if (board[row][col] != '.') return solve(board, row, col + 1); // Skip prefilled cell

        for (int k = 1; k <= 9; k++) {
            if (isSafe(board, row, col, k)) {
                char digit = k + '0';
                board[row][col] = digit;
                int boxNo = (row / 3) * 3 + (col / 3);
                s[boxNo].insert(digit);

                if (solve(board, row, col + 1)) return true;

                // Backtrack
                board[row][col] = '.';
                s[boxNo].erase(digit);
            }
        }

        return false; // No valid digit found
    }

    // Entry point
    void solveSudoku(vector<vector<char>>& board) {
        fillSubBox(board); // Setup sub-boxes with initial state
        solve(board, 0, 0); // Start solving
    }
};
