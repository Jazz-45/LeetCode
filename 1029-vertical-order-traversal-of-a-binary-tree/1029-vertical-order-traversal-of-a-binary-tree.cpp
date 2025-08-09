class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;
        
        // queue stores: node, (col, row)
        queue<pair<TreeNode*, pair<int,int>>> todo;
        todo.push({root, {0, 0}});
        
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            
            TreeNode* node = p.first;
            int x = p.second.first;   // column
            int y = p.second.second;  // row
            
            nodes[x][y].insert(node->val);
            
            if (node->left) {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right) {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        
        vector<vector<int>> ans;
        for (auto &p : nodes) {
            vector<int> col;
            for (auto &q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
