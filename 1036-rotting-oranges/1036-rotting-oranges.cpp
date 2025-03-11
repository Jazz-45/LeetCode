class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    // BFS Starting Point
                    q.push({{i,j},0});
                }
            }
        }
        int minutes=0;

        // Starting BFS
        while(!q.empty()){
            auto p=q.front();
            int i=p.first.first;
            int j=p.first.second;
            q.pop();

            int delRow[]={1,-1,0,0};
            int delCol[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                    int ncol=j+delCol[k];
                    int nrow=i+delRow[k];
                    if(ncol>=0 && ncol<n && nrow>=0 && nrow<m && grid[nrow][ncol]==1
                    && grid[nrow][ncol]!=2){
                        q.push({{nrow,ncol},p.second+1});
                        grid[nrow][ncol]=2;
                    }
            }
            minutes=p.second;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return minutes;


    }
};