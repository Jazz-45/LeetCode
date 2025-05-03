// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         vector<int> vis(n,0);

//         queue<int> q;

//         int provinces=0;

//         for(int i=0;i<n;i++){
//             // Loop for finding connected elemnts
//             if(!vis[i]){
//                 // Found 1 Province
//                 provinces++;

//                 q.push(i);
//                 vis[i]=1;

//                 while(!q.empty()){
//                     int node=q.front();
//                     q.pop();

//                     for(int j=0;j<n;j++){
//                         if(isConnected[node][j]==1){
//                             if(!vis[j]){
//                                 q.push(j);
//                                 vis[j]=1;
//                             }
//                         }
//                     }
//                 }
//             }

//         }

//         return provinces;

//     }
// };

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        DisjointSet ds(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    if(ds.findParent(i)!=ds.findParent(j)){
                        ds.unionBySize(i,j);
                    }
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) count++;
        }
        return count;
    }
};