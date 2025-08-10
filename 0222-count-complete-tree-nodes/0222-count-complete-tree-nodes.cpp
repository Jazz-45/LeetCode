class Solution {
public:
    int getLeftHeight(TreeNode* root){
        TreeNode* temp=root;
        int h=0;

        while(temp){
            temp=temp->left;
            h++;
        }
        return h;
    }
    int getRightHeight(TreeNode* root){
        TreeNode* temp=root;
        int h=0;

        while(temp){
            temp=temp->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh=getLeftHeight(root);
        int rh=getRightHeight(root);

        if(lh==rh) return pow(2,lh)-1;

        return countNodes(root->left)+countNodes(root->right)+1;
    }
};