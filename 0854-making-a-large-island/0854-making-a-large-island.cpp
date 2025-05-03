class DisjointSet{
    
    public:
        vector<int> rank,parent,size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }

        int findParent(int node){
            if(node==parent[node]) return node;
            return parent[node]=findParent(parent[node]);
        }

        void unionBySize(int u,int v){
            int ulp_u=findParent(u);
            int ulp_v=findParent(v);

            if(ulp_u==ulp_v) return;

            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            else{
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
        }
};

class Solution {
public:
    bool isValid(int newr,int newc,int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        DisjointSet ds(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dx[]={-1,1,0,0};
                int dy[]={0,0,1,-1};
                for(int k=0;k<4;k++){
                    int newr=i+dx[k];
                    int newc=j+dy[k];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        int node=i*n+j;
                        int newnode=newr*n+newc;
                        ds.unionBySize(node,newnode);
                    }
                }
            }
        }

        // Step-2
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dx[]={-1,1,0,0};
                int dy[]={0,0,1,-1};

                set<int> components;

                for(int k=0;k<4;k++){
                    int newr=i+dx[k];
                    int newc=j+dy[k];
                    if(isValid(newr,newc,n) && grid[newr][newc]==1){
                        components.insert(ds.findParent(newr*n+newc));
                    }
                }
                int sizeTotal=1;
                for(auto it: components){
                    sizeTotal +=ds.size[it];
                }
                mx=max(mx,sizeTotal);
            }
        }

        for(int i = 0; i < n*n; i++) {
            mx = max(mx, ds.size[ds.findParent(i)]);

        }
        return mx;

    }
};