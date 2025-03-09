class Solution {
public:
    int ans;

    // DP 
    //unordered_map<TreeNode*,int> mp;
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        
        int leftLevels=levels(root->left);
        int rightLevels=levels(root->right);
        int myDia=leftLevels+rightLevels;
        ans=max(ans,myDia);
        return 1+max(leftLevels,rightLevels);

        // Basic Memoization
        // if(mp.find(root)!=mp.end()) return mp[root];
        // return mp[root]=1+max(levels(root->left),levels(root->right));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {

        ans=0;
        levels(root);
        return ans;
    }
};