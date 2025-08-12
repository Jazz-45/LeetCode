/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        TreeNode* og = root;
        while (og) {
            if (val > og->val) {
                if (og->right)
                    og = og->right;
                else {
                    og->right = new TreeNode(val);
                    break;
                }
            } else if (og->left)
                og = og->left;
            else {
                og->left = new TreeNode(val);
                break;
            }
        }
        
        return root;
    }
};