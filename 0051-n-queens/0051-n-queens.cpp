class Solution {
public:
    vector<vector<string>> ans;

    bool canPlace(vector<string>& board,int row,int col){
        int n=board.size();
        // Checking Upwards
        for(int r=row;r>=0;r--){
            if(board[r][col]=='Q') return false;
        }

         // Check left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // Check right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void helper(vector<string>& board,int n,int row){

        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(canPlace(board,row,col)==true){
                board[row][col]='Q';
                helper(board,n,row+1);
                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        ans.clear();

        vector<string> temp(n);
        for(int i=0;i<n;i++){
            string str="";
            for(int j=0;j<n;j++) str.push_back('.');
            temp[i]=str;
        }

        helper(temp,n,0);
        return ans;


    }
};