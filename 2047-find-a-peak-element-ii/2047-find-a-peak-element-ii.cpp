class Solution {
public:
    // Question is simple as we have to find only one peak element
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();

        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

             if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            } else if (left > mat[maxRow][mid]) {
                high = mid - 1;  // move left
            } else {
                low = mid + 1;   // move right
            }
        }
        return {-1,-1};
    }
};