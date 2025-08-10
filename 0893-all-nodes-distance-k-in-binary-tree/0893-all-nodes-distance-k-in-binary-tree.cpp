class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> m; // {Child,Parent}
    unordered_set<TreeNode*> s;
    
    void inorder(TreeNode* root){
        if(root==NULL) return;

        if(root->left) m.insert({root->left,root});
        if(root->right) m.insert({root->right,root});

        inorder(root->left);
        inorder(root->right);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(root==NULL) return ans;

        inorder(root);

        queue<pair<TreeNode*,int>> q; // Node,Distance
        q.push({target,0});
        s.insert(target);

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            TreeNode* node=p.first;
            int distance=p.second;

            if(distance==k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left && s.find(node->left)==s.end()){
                q.push({node->left,distance+1});
                s.insert(node->left);
            }
            if(node->right && s.find(node->right)==s.end()){
                q.push({node->right,distance+1});
                s.insert(node->right);
            }

            if(m.find(node)!=m.end() && s.find(m[node])==s.end()){
                q.push({m[node],distance+1});
                s.insert(m[node]);
            }
        }

        return ans;
    }
};