class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }

        for(int i=0;i<s.length();i++){
            if(m.find(t[i])==m.end()) return false;
            else{
                 m[t[i]]--;
                 if(m[t[i]]==0) m.erase(t[i]);
            }
        }

        for(auto p: m){
            if(p.second>1) return false;
        }

        return true;

        
    }
};