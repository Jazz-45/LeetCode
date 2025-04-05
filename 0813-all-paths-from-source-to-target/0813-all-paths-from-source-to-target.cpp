class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;

        queue<vector<int>> q;
        q.push({0});

        while(!q.empty()){
            vector<int> path=q.front();
            q.pop();

            int lastNode=path[path.size()-1];
            if(lastNode==n-1) ans.push_back(path);

            for(int x: graph[lastNode]){
                vector<int> temp=path;
                temp.push_back(x);
                q.push(temp);
            }
        }
        return ans;
    }
};