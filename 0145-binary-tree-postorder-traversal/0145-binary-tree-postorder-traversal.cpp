
class Solution {
public:
    vector<int> ans;
    
    void traversal(TreeNode* root){
        if(root==NULL) return;
        
        traversal(root->left);
        traversal(root->right);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        ans.clear();
        traversal(root);
        return ans;
    }
};