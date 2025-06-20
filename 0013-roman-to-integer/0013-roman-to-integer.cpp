class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;

        int ans=0;
        int i=0;
        while(i<s.length()){
            // Check if there is any bigger notation next to it
            if(m[s[i]]<m[s[i+1]]){
                ans+=(m[s[i+1]]-m[s[i]]);
                i+=2;
            }
            else{
                ans+=m[s[i]];
                i++;
            }
        }
        return ans;

    }
};