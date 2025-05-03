class Solution {
public:
    int time=1;
    void dfs(int node,int parent,vector<int> &vis,vector<vector<int>> &adj,
            vector<int>& dis,vector<int> &low, vector<vector<int>> &bridges){
        vis[node]=1;
        dis[node]=low[node]=time++;

        for(int x: adj[node]){
            if(x==parent) continue;
            if(!vis[x]){
                dfs(x,node,vis,adj,dis,low,bridges);
                low[node]=min(low[node],low[x]);

                if(low[x]>dis[node]){
                    // Bridge Found
                    bridges.push_back({node,x});
                }
            }
            else{
                // If visited
                low[node]=min(low[node],low[x]);
            }
        }

    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Creating and adjList
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        // Creating dis[] and low[]
        vector<int> dis(n),low(n),vis(n);
        vector<vector<int>> bridges;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,adj,dis,low,bridges);
            }
        }
        return bridges;
    }
};