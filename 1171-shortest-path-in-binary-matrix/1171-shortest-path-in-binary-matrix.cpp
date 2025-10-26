class Solution {
public:
    bool isValid(int nrow,int ncol,int n){
        return nrow>=0 && ncol>=0 && nrow<n && ncol<n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;

        while(!q.empty()){
            auto p=q.front(); 
            q.pop();
            int x=p.first.first;
            int y=p.first.second;

            if(x==n-1 && y==n-1) return p.second;

            int dirs[]={-1,0,1};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j && j==1) continue; // Reject 0,0

                    int nrow=x+dirs[i];
                    int ncol=y+dirs[j];
                    if(isValid(nrow,ncol,n) && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                        q.push({{nrow,ncol},p.second+1});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
        return -1;
    }
};