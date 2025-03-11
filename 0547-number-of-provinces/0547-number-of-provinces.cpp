class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);

        queue<int> q;

        int provinces=0;

        for(int i=0;i<n;i++){
            // Loop for finding connected elemnts
            if(!vis[i]){
                // Found 1 Province
                provinces++;

                q.push(i);
                vis[i]=1;

                while(!q.empty()){
                    int node=q.front();
                    q.pop();

                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]==1){
                            if(!vis[j]){
                                q.push(j);
                                vis[j]=1;
                            }
                        }
                    }
                }
            }

        }

        return provinces;

    }
};