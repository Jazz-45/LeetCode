class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || j==n-1 || i==m-1)){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow=i+dx[k];
                int ncol=j+dy[k];

                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && !vis[nrow][ncol]
                && board[nrow][ncol]=='O'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        // Converting O to X
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    board[i][j]='X';
                }
            }
        }

    }
};