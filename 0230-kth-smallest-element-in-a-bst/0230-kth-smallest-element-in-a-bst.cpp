class Solution {
public:
    int ans = -1;
    int count = 0;

    void inorder(TreeNode* root, int k) {
        if (!root) return;

        inorder(root->left, k);

        count++;
        if (count == k) {
            ans = root->val;
            return; // Found k-th smallest, can stop further traversal
        }

        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
