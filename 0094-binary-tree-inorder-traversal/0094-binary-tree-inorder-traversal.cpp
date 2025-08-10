
class Solution {
public:
    vector<int> ans;
    
    void traversal(TreeNode* root){
        if(root==NULL) return;
        
        traversal(root->left);
        ans.push_back(root->val);
        traversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        ans.clear();
        traversal(root);
        return ans;
    }
};