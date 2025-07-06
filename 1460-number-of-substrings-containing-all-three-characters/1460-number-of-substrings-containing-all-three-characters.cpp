class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        unordered_map<char,int> m;
        m['a']=-1;
        m['b']=-1;
        m['c']=-1;

        int count=0;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
            if(m['a']!=-1 && m['c']!=-1 && m['b']!=-1){
                int lastSeen=min({m['a'],m['b'],m['c']});
                count+=lastSeen+1;
            }
        }
        return count;
    }
};