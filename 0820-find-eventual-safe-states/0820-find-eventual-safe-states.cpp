class Solution {
public:
    // bool dfs(vector<vector<int>> &adj,vector<int>& vis,vector<int>& pathVis, int node,vector<int>& check){
    //     vis[node]=1;
    //     pathVis[node]=1;
    //     for(int x: adj[node]){
    //         if(!vis[x]){
    //             if(dfs(adj,vis,pathVis,x,check)) return true;
    //         }
    //         else{
    //             if(pathVis[x]) return true;
    //         }
    //     }
    //     check[node]=1;
    //     pathVis[node]=0;
    //     return false;
    // }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<int> vis(n,0),pathVis(n,0),check(n,0);
        // vector<int> safeStates;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]) dfs(graph,vis,pathVis,i,check);
        // }
        // for(int i=0;i<n;i++){
        //     if(check[i]) safeStates.push_back(i);
        // }
        // return safeStates;

        // BFS Kahn's Algorithm
        
        // Making a new reverse direction list
        vector<vector<int>> adj(n,vector<int>());
        for(int i=0;i<n;i++){
            for(int x: graph[i]) adj[x].push_back(i); 
        }

        vector<int> ans;
        queue<int> q;
        
        vector<int> inDegree(n,0);
        for(int i=0;i<n;i++){
            for(int x: adj[i]) inDegree[x]++;
        }
        
        for(int i=0;i<n;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int x: adj[node]){
                inDegree[x]--;
                if(inDegree[x]==0) q.push(x);
            }
            ans.push_back(node);
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};