class Codec {
   public:
    string serialize(TreeNode* root) {
        if (!root) return "";

        string str = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                str.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            } else {
                str.append("#,");
            }
        }
        str.pop_back();
        return str;
    }

    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, str, ',');

            if (str == "#") {
                node->left = nullptr;
            } else {
                TreeNode* newNode = new TreeNode(stoi(str));
                node->left = newNode;
                q.push(newNode);
            }

            getline(ss, str, ',');

            if (str == "#") {
                node->right = nullptr;
            } else {
                TreeNode* newNode = new TreeNode(stoi(str));
                node->right = newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};
