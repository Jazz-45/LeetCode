class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        using T = pair<int, pair<int, int>>; // {value, {row, col}}

        priority_queue<T, vector<T>, greater<T>> minHeap;

        // Step 1: Push the first element of each row
        for (int row = 0; row < n; ++row) {
            minHeap.push({matrix[row][0], {row, 0}});
        }

        // Step 2: Pop k-1 elements
        while (--k) {
            auto [val, coord] = minHeap.top();
            minHeap.pop();
            int r = coord.first;
            int c = coord.second;

            // Push the next element in the same row (if exists)
            if (c + 1 < n) {
                minHeap.push({matrix[r][c + 1], {r, c + 1}});
            }
        }

        // Step 3: k-th smallest element is on top of the heap
        return minHeap.top().first;
    }
};
