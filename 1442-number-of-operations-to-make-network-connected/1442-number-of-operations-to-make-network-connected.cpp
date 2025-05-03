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
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int extraEdges=0;

        for(auto x: connections){
            int u=x[0],v=x[1];
            int ulp_u=ds.findParent(u);
            int ulp_v=ds.findParent(v);

            if(ulp_u == ulp_v) extraEdges++;
            else{
                ds.unionBySize(u,v);
            }
        }

        int components=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) components++;
        }

        if(extraEdges>=components-1) return components-1;
        else return -1;
    }
};