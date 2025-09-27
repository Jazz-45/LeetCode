class TrieNode {
public:
    bool wordEnd;
    string word; // store full word when end
    vector<TrieNode*> link;

    TrieNode() {
        wordEnd = false;
        word = "";
        link.resize(26, nullptr);
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->link[idx] == nullptr)
                curr->link[idx] = new TrieNode();
            curr = curr->link[idx];
        }
        curr->wordEnd = true;
        curr->word = word; // store the word at the end
    }
};

class Solution {
public:
    int m, n;
    vector<string> ans;
    vector<vector<char>> board;

    void dfs(int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || node->link[c - 'a'] == nullptr) return;

        node = node->link[c - 'a'];
        if (node->wordEnd) {
            ans.push_back(node->word);
            node->wordEnd = false; // avoid duplicate results
        }

        // mark visited
        board[i][j] = '#';

        // explore neighbors
        if (i > 0) dfs(i - 1, j, node);
        if (i < m - 1) dfs(i + 1, j, node);
        if (j > 0) dfs(i, j - 1, node);
        if (j < n - 1) dfs(i, j + 1, node);

        // unmark
        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string& w : words) trie.insert(w);

        this->board = board;
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(i, j, trie.root);
            }
        }

        return ans;
    }
};
