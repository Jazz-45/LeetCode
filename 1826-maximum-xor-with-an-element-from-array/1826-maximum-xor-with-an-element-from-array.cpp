class TrieNode{
public:
    TrieNode* link[2];
    TrieNode(){
        link[0]=NULL;
        link[1]=NULL;
    }
};

class Trie{
    TrieNode* root;
public:
    Trie(){
        root=new TrieNode();
    }
    void insert(int num){
        TrieNode* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->link[bit])node->link[bit]=new TrieNode();
            node=node->link[bit];
        }
    }
    int getMax(int num){
        TrieNode* node=root;
        if(!node->link[0]&&!node->link[1])return -1;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->link[1-bit]){
                ans|=(1<<i);
                node=node->link[1-bit];
            }else node=node->link[bit];
        }
        return ans;
    }
};

class Solution{
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        sort(nums.begin(),nums.end());
        
        vector<array<int,3>> q;
        
        for(int i=0;i<queries.size();i++) q.push_back({queries[i][1],queries[i][0],i});
        
        sort(q.begin(),q.end());
        
        Trie trie;
        vector<int> ans(queries.size());
        int idx=0,n=nums.size();
        for(auto &qq:q){
            int mi=qq[0],x=qq[1],qi=qq[2];
            while(idx<n&&nums[idx]<=mi) trie.insert(nums[idx++]);
            ans[qi]=trie.getMax(x);
        }
        return ans;
    }
};
