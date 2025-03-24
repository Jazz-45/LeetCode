class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& arr) {
        int n=arr.size();

        vector<vector<int>> adj(numCourses,vector<int>());

        // Created Adj List
        for(int i=0;i<n;i++){
            adj[arr[i][1]].push_back(arr[i][0]);
        }

        vector<int> topoSort;
        queue<int> q;
        
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int x: adj[i]) inDegree[x]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0) q.push(i);
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(int x: adj[node]){
                inDegree[x]--;
                if(inDegree[x]==0) q.push(x);
            }
            topoSort.push_back(node);
        }

        if(topoSort.size()!=numCourses) return false;
        else return true;

    }
};