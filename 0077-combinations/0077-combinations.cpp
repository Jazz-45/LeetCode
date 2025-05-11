class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n, int k, int i,vector<int>& arr){
        if(k==0){
            ans.push_back(arr);
            return;
        }
        
        for(int j=i;j<=n;j++){
            arr.push_back(j);
            solve(n,k-1,j+1,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> arr;
        solve(n,k,1,arr);
        return ans;
    }
};