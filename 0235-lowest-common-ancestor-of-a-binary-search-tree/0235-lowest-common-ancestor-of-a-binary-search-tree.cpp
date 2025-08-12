class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return root;

        if(min(p->val,q->val)>root->val) return lowestCommonAncestor(root->right,p,q);
        else if(max(p->val,q->val)<root->val) return lowestCommonAncestor(root->left,p,q);
        else return root;
    }
};