class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>& vis,int i){
        queue<int> q;
        q.push(i);
        vis[i] = 0;

        while (!q.empty()) {
            int node=q.front();
            q.pop();
            for (int x :graph[node]) {
                if (vis[x]==-1){
                    q.push(x);
                    if (vis[node]==1) vis[x]=0;
                    else vis[x]=1;
                } 
                else{
                    if (vis[node]==vis[x]) return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>& graph,vector<int>& vis,int i,int color){
        vis[i]=color;
        for(int x: graph[i]){
            if(vis[x]==-1){
                if (!dfs(graph, vis, x, !color)) return false;
            }
            else{
                if(vis[x]==vis[i]) return false;
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);

        // Loop for all connected components
        // BFS Approach
        // for (int i = 0; i < n; i++) {
        //     if (vis[i]==-1) {
        //         if(bfs(graph,vis,i)==false) return false;
        //     }
        // }

        // DFS Approach
        for (int i = 0; i < n; i++) {
            if (vis[i]==-1) {
                if(dfs(graph,vis,i,0)==false) return false;
            }
        }

        return true;
    }
};