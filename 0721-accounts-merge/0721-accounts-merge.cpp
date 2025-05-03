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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        DisjointSet ds(n);
        unordered_map<string,int> m;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];

                if(m.find(mail)==m.end())m[mail]=i;
                else{// If finds the same mail in the map, the merge
                    ds.unionBySize(i,m[mail]);
                }
            }
        }

        // Merging the Mail
        vector<string> mergedMail[n];
        for (auto it : m) {
            string mail = it.first;
            int node = ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }

        // Sorting and returning the ans

        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {
            if (mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};