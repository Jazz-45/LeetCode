class Solution {
public:
    
    int pathSum(TreeNode* root,int& sum){
        if(root==NULL) return 0;

        // Get max path sum from left and right; ignore negatives
        int leftSum=max(0,pathSum(root->left,sum));
        int rightSum=max(0,pathSum(root->right,sum));

        // Update global max if needed (including current node + both sides)
        sum=max(sum,leftSum+rightSum+root->val);


        return root->val+max(leftSum,rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        pathSum(root,sum);
        return sum;
    }
};