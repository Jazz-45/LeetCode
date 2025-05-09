class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates,int target,int idx,vector<int>& seq){
        if(target==0){
            ans.push_back(seq);
            return;
        }
        if(idx==candidates.size()) return;
        if(candidates[idx]<=target){
            seq.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],idx+1,seq);
            seq.pop_back();
        }

        // Avoid call -> Very Impotant
        int j=idx+1;
        // Skipping the same numbers
        while(j<candidates.size() && candidates[j]==candidates[j-1]) j++;
        solve(candidates,target,j,seq);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        ans.clear();
        vector<int> seq;
        solve(candidates,target,0,seq);
        return ans;
    }
};