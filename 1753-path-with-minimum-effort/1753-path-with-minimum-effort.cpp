class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();

        vector<vector<int>> distance(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        distance[0][0] = 0;

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int diff = p.first;
            int row = p.second.first;
            int col = p.second.second;

            if(row==m-1 && col==n-1) return diff;

            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n){
                    // Push only when a shorter distance to that cell is found
                    int newEffort=max(abs(grid[row][col]-grid[nrow][ncol]),diff);

                    if(newEffort<distance[nrow][ncol]){
                        distance[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;


    }
};