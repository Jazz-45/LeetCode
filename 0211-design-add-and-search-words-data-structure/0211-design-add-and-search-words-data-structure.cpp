class TrieNode{
  public : 
    bool wordEnd;
    vector<TrieNode*> link;
    TrieNode(){
        wordEnd=false;
        link.resize(26,nullptr);
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr=root;
        for(int i=0;i<word.length();i++){
            int idx=word[i]-'a';
            if(curr->link[idx]==NULL) curr->link[idx]=new TrieNode();
            curr=curr->link[idx];
        }
        curr->wordEnd=true;
    }

    bool helper(string &word, int idx, TrieNode* curr) {
        if (idx == word.size()) return curr->wordEnd;

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if(curr->link[i]!=nullptr && helper(word,idx+1,curr->link[i])) return true;
            }
            return false;
        } else {
            int charIdx = word[idx] - 'a';
            if (curr->link[charIdx] == nullptr) return false;
            return helper(word, idx+1, curr->link[charIdx]);
        }
    }

    
    bool search(string word) {
        TrieNode* curr=root;
        return helper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */