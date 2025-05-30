class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sorting
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;

        int startTime=intervals[0][0],endTime=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=endTime){
                endTime = max(endTime, intervals[i][1]);
            }
            else{
                ans.push_back({startTime,endTime});
                startTime=intervals[i][0];
                endTime=intervals[i][1];
            }
        }
        ans.push_back({startTime, endTime});

        return ans;
    }
};