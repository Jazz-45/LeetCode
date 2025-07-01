class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int> st;
        vector<int> ans(n,0);

        // Back traversal the array -> virtually doubling the array
        for(int i=2*n-1;i>=0;i--){
            int idx=i%n;

            while(!st.empty() && nums[idx]>=st.top()) st.pop();
           

            if(i<=n-1){
                if(st.empty()) ans[i]=-1;
                else ans[i]=st.top();
            }
            st.push(nums[idx]);
        }
        return ans;
    }
};