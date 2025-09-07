class TrieNode{
public:
    TrieNode* link[2];
    TrieNode(){
        link[0]=NULL;
        link[1]=NULL;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode* curr=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(curr->link[bit]==NULL) curr->link[bit]=new TrieNode();
            curr=curr->link[bit];
        }
    }
    int getMaxXor(int num){
        TrieNode* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1; 
            if(curr->link[1-bit]!=NULL){
                ans|=(1<<i);
                curr=curr->link[1-bit];
            }else curr=curr->link[bit];
        }
        return ans;
    }
};

class Solution{
public:
    int findMaximumXOR(vector<int>& nums){
        Trie trie;
        for(int num:nums) trie.insert(num);
        int maxi=0;
        for(int num:nums) maxi=max(maxi,trie.getMaxXor(num));
        return maxi;
    }
};