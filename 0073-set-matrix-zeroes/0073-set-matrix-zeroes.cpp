class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowHasZero = false, firstColHasZero = false;

        // Step 1: Check if first row has any zero
        for(int j = 0; j < cols; j++) {
            if(matrix[0][j] == 0) {
                firstRowHasZero = true;
                break;
            }
        }

        // Step 2: Check if first column has any zero
        for(int i = 0; i < rows; i++) {
            if(matrix[i][0] == 0) {
                firstColHasZero = true;
                break;
            }
        }

        // Step 3: Use first row and column as flags
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 4: Zero out cells based on flags
        for(int i = 1; i < rows; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for(int j = 1; j < cols; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 5: Zero out first row and column if needed
        if(firstRowHasZero) {
            for(int j = 0; j < cols; j++) matrix[0][j] = 0;
        }

        if(firstColHasZero) {
            for(int i = 0; i < rows; i++) matrix[i][0] = 0;
        }
    }
};
