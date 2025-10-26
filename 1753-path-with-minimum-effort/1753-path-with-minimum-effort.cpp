class Solution {
public:
    bool isValid(int nrow,int ncol,int n,int m){
        return nrow>=0 && ncol>=0 && nrow<n && ncol<m;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;


        dist[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int x=p.second.first; int y=p.second.second;
            int effort=p.first;

            int dx[]={1,-1,0,0};
            int dy[]={0,0,1,-1};

            for(int k=0;k<4;k++){
                int newr=x+dx[k],newc=y+dy[k];

                if(isValid(newr,newc,n,m)){
                    int newEffort=max(effort,abs(heights[x][y]-heights[newr][newc]));
                    if(newEffort<dist[newr][newc]){
                        pq.push({newEffort,{newr,newc}});
                        dist[newr][newc]=newEffort;
                    }
                }
            }
            
        }

        return dist[n-1][m-1];
    }
};