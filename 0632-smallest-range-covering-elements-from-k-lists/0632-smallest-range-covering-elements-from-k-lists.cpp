typedef pair<int,pair<int,int>> p;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<p> first_elements;

        int high = nums[0][0];
        for (int i = 0; i < n; i++) {
            first_elements.push_back({nums[i][0], {i, 0}});
            high = max(high, nums[i][0]);
        }

        priority_queue<p, vector<p>, greater<p>> pq(first_elements.begin(), first_elements.end());
        int range = INT_MAX;
        int best_low = 0, best_high = 0;

        while (pq.size() == n) {
            auto x = pq.top();
            pq.pop();

            int low = x.first;
            if ((high - low) < range) {
                range = high - low;
                best_low = low;
                best_high = high;
            }

            int row = x.second.first;
            int col = x.second.second;

            if (col + 1 < nums[row].size()) {
                int next_val = nums[row][col + 1];
                pq.push({next_val, {row, col + 1}});
                high = max(high, next_val);
            }
        }

        return {best_low, best_high};
    }
};
