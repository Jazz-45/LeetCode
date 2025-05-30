class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Implement Left -> Right -> Top -> Bottom

        int top=0,left=0,bottom=matrix.size()-1,right=matrix[0].size()-1;
        vector<int> ans;

        while(top<=bottom && left<=right){

            //Left->Right
            for(int i=left;i<=right;i++) ans.push_back(matrix[top][i]);
            top++;

            //Top->Bottom
            for(int i=top;i<=bottom;i++) ans.push_back(matrix[i][right]);
            right--;

            //Right->Left
            if(top<=bottom){
                for(int i=right;i>=left;i--) ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            //Bottom ->up
            if(left<=right){
                for(int i=bottom;i>=top;i--) ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};