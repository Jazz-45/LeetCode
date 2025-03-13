class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || j==n-1 || i==m-1)){
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
                && grid[nrow][ncol]==1){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        // Counting
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};