class TrieNode{
public:
    
    vector<TrieNode*> link;
    bool flag=false;
    TrieNode(){
        link.resize(26,nullptr);
    }
};

class Trie {

  private:
    TrieNode* root;

  public:
    
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr=root;
        for(char key: word){
            if(curr->link[key-'a']==NULL){
                // Character not present -> make a new Node
                TrieNode* newNode=new TrieNode();
                curr->link[key-'a']=newNode;
            }
            // Moving to already exixting or the link made recently
            curr=curr->link[key-'a'];
        }
        // Setting the end bool
        curr->flag=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char key: word){
            if(curr->link[key-'a']==NULL) return false;
            curr=curr->link[key-'a'];
        }

        return curr->flag; // IMP Step
    }
    
    bool startsWith(string word) {
        TrieNode* curr=root;
        for(char key: word){
            if(curr->link[key-'a']==NULL) return false;
            curr=curr->link[key-'a'];
        }

        return true; // IMP Step
    }
};