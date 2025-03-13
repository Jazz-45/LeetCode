class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, -1);

        // Loop for all connected components
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                queue<int> q;
                q.push(i);
                vis[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int x : graph[node]) {
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
            }
        }
        return true;
    }
};