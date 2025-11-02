class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // -1 = wall, 2 = guard, 1 = guarded
        for(auto &w : walls) grid[w[0]][w[1]] = -1;
        for(auto &g : guards) grid[g[0]][g[1]] = 2;
        
        // Sweep rows (left to right)
        for(int i = 0; i < m; i++){
            bool seen = false;
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) seen = true;
                else if(grid[i][j] == -1) seen = false;
                else if(seen && grid[i][j] == 0) grid[i][j] = 1;
            }
            seen = false;
            for(int j = n - 1; j >= 0; j--){
                if(grid[i][j] == 2) seen = true;
                else if(grid[i][j] == -1) seen = false;
                else if(seen && grid[i][j] == 0) grid[i][j] = 1;
            }
        }

        // Sweep columns (top to bottom)
        for(int j = 0; j < n; j++){
            bool seen = false;
            for(int i = 0; i < m; i++){
                if(grid[i][j] == 2) seen = true;
                else if(grid[i][j] == -1) seen = false;
                else if(seen && grid[i][j] == 0) grid[i][j] = 1;
            }
            seen = false;
            for(int i = m - 1; i >= 0; i--){
                if(grid[i][j] == 2) seen = true;
                else if(grid[i][j] == -1) seen = false;
                else if(seen && grid[i][j] == 0) grid[i][j] = 1;
            }
        }

        // Count unguarded cells
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) ans++;
            }
        }
        return ans;
    }
};
