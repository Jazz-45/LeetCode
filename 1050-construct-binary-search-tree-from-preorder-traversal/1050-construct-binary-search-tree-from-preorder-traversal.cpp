class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& idx , int ub){
        if(idx>= preorder.size() || preorder[idx]>ub) return NULL;

        TreeNode* node=new TreeNode(preorder[idx++]);
        node->left=build(preorder,idx,node->val);
        node->right=build(preorder,idx,ub);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build(preorder,idx,INT_MAX);
    }
};