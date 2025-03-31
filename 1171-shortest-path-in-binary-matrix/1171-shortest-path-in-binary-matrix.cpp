class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // if starting or ending cell is blocked, return -1
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
           
        
        // priority queue (min-heap) storing {distance, {row, col}}
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0, {0, 0}});
        
        // distance matrix initialized to INT_MAX
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        distance[0][0] = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int dist = p.first;
            int row = p.second.first;
            int col = p.second.second;
            
            // If we reached the destination, return the path length (add 1 for cell count)
            if(row == n-1 && col == n-1)
                return dist + 1;
            
            // Explore all 8 directions
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(i == 0 && j == 0) continue; // Skip the current cell
                    
                    int nrow = row + i;
                    int ncol = col + j;
                    
                    // Check boundaries first, then if the cell is clear (0)
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0){
                        // Push only when a shorter distance to that cell is found
                        if(dist + 1 < distance[nrow][ncol]){
                            distance[nrow][ncol] = dist + 1;
                            pq.push({dist + 1, {nrow, ncol}});
                        }
                    }
                }
            }
        }
        // Destination unreachable
        return -1;
    }
};
