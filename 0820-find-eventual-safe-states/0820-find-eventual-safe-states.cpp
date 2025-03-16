class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<int>& vis,vector<int>& pathVis, int node,vector<int>& check){
        vis[node]=1;
        pathVis[node]=1;
        for(int x: adj[node]){
            if(!vis[x]){
                if(dfs(adj,vis,pathVis,x,check)) return true;
            }
            else{
                if(pathVis[x]) return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        vector<int> safeStates;
        vector<int> check(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(graph,vis,pathVis,i,check);
            }
        }
        for(int i=0;i<n;i++){
            if(check[i]) safeStates.push_back(i);
        }
        return safeStates;
    }
};