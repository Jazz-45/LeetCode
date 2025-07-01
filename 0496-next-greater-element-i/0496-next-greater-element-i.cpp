class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> ans(nums1.size(),-1);

        for(int i=0;i<nums1.size();i++){
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    if(st.empty()) continue;
                    else ans[i]=st.top();
                }
                else if(nums2[j]>nums1[i]) st.push(nums2[j]);
                else continue;
            }
            while(st.size()) st.pop();
        }
        return ans;
    }
};