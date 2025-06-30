class Solution {
public:
    bool search(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        int m = board.size(), n = board[0].size();

        // Out of bounds
        if (row < 0 || row >= m || col < 0 || col >= n) return false;

        // Current cell doesn't match the current character
        if (board[row][col] != word[idx]) return false;

        // If it's the last character and it matches
        if (idx == word.size() - 1) return true;

        // Mark the current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore in all four directions
        bool found = search(board, word, idx + 1, row + 1, col) ||
                     search(board, word, idx + 1, row - 1, col) ||
                     search(board, word, idx + 1, row, col + 1) ||
                     search(board, word, idx + 1, row, col - 1);

        // Restore the original character (backtrack)
        board[row][col] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, 0, i, j)) return true;
                }
            }
        }
        return false;
    }
};
