class Solution {
public:
    vector<unordered_set<char>> grid;
    bool isValid(vector<vector<char>>& board,int row,int col){

        int boxIdx=(row/3)*3+(col/3);

        // Checking Upwards
        for(int j=row-1;j>=0;j--){
            if(board[j][col]==board[row][col]) return false;
        }

        // Checking LeftWards
        for(int i=col-1;i>=0;i--){
            if(board[row][i]==board[row][col]) return false;
        }

        // Checking in Sub-Boxes
        if(grid[boxIdx].empty()){
            grid[boxIdx].insert(board[row][col]);
        }
        else{
            if(grid[boxIdx].find(board[row][col])!=grid[boxIdx].end()) return false;
            grid[boxIdx].insert(board[row][col]);
        }

        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        grid.clear();
        grid.resize(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(isValid(board,i,j)==false) return false;
                }
            }
        }
        return true;
    }
};