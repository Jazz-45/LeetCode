class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>> ans;
        int i=0;
        // Left portions -> add as it is
        // intervals that end before new Interval
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // Compute new Interval -> merge and then add
        // Intervals that start before the end of new Interval
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        // Right part
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;

    }
};