class Solution {
public:

    void bfs(vector<vector<int>>& isWater,vector<vector<int>>& vis,int i,int j){
        queue<pair<int,int>> q;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();

        vector<vector<int>> ans(m,vector<int>(n,-1));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;

            int delrow[]={1,-1,0,0};
            int delcol[]={0,0,1,-1};

            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && ans[nrow][ncol]==-1){
                        ans[nrow][ncol]=1+ans[i][j];
                        q.push({nrow,ncol});
                    }
            }
        }

        return ans;
        

    }
};