class DisjointSet{
    public:
    vector<int> parent,rank;
    
    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    
    void unionByRank(int u,int v){
        int pu=findParent(u),pv=findParent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pu]>rank[pv]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int cables=connections.size();
        if(cables<n-1) return -1; // MST condition

        int extraCables=0;
        DisjointSet dsu(n);

        for(auto it: connections){
            int u=it[0],v=it[1];
            if(dsu.findParent(u)!=dsu.findParent(v)){
                dsu.unionByRank(u,v);
            }
            else{
                // Extra Cables
                extraCables++;
            }
        }

        int remNodes=0;
        for(int i=0;i<n;i++){
            if(i==dsu.parent[i]) remNodes++;
        }

        return remNodes-1;


        
    }
};