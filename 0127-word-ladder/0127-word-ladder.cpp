class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();

        // Mapping
        unordered_set<string> s1,s2;

        for(string temp: wordList) s1.insert(temp);
        vector<int> vis(n,0);

        queue<pair<string,int>> q;
        q.push({beginWord,0});
        s2.insert(beginWord);

        while(!q.empty()){
            auto p=q.front();
            q.pop();
            string str=p.first;
            if(str==endWord) return p.second+1;
            
            int wordLen=str.length();
            bool flag=true;
            for(int i=0;i<wordLen;i++){
                for(int j=(int)('a');j<=(int)('z');j++){
                    string temp=str;
                    temp[i]=(char)(j);

                    // The endWord is found
                    if(s1.find(temp)!=s1.end() && s2.find(temp)==s2.end()){
                        q.push({temp,p.second+1});
                        s2.insert(temp);
                        flag=true;
                    }
                }
            }
            if(flag==false && q.empty()) return 0;

        }

        return 0;

    }
};