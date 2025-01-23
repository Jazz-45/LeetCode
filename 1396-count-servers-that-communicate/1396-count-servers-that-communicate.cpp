class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        vector<int> row(m),col(n);

        for(int i=0;i<m;i++){
            int rowSum=0;
            for(int j=0;j<n;j++) if(grid[i][j]==1) rowSum++;
            row[i]=rowSum;
        }

        for(int j=0;j<n;j++){
            int colSum=0;
            for(int i=0;i<m;i++) if(grid[i][j]==1) colSum++;
            col[j]=colSum;
        }

        int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(((row[i]>1) || (col[j]>1))&&(grid[i][j])) result++;
            }
        }

        return result;

    }
};