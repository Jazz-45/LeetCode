class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();

        queue<pair<int,int>> q;

        // Starting bfs from '0' at edges
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O') q.push({i,0});
            if(grid[i][n-1]=='O') q.push({i,n-1});
        }
        for(int j=0;j<n;j++){
            if(grid[0][j]=='O') q.push({0,j});
            if(grid[m-1][j]=='O') q.push({m-1,j});
        }

        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            grid[x][y]='#';
            
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<=3;i++){
                int di=x+dx[i],dj=y+dy[i];
                if(di>=0 && di<m && dj>=0 && dj<n && grid[di][dj]=='O'){
                    q.push({di,dj});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='#') grid[i][j]='O';
                else grid[i][j]='X';
            }
        }
    }
};