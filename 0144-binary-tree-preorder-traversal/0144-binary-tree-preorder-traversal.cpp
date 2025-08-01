class Solution {
public:
    vector<int> ans;
    
    void traversal(TreeNode* root){
        if(root==NULL) return;
        
        ans.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        traversal(root);
        return ans;
    }
};