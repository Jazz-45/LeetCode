class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        
        short cnt=0;
        string temp;
        for(int i=0;i<s.length();i++){
            if(cnt>0 && cnt%k==0){
                ans.push_back(temp);
                temp="";
            }
            temp+=s[i];
            cnt++;
        }

        while(cnt%k){
            temp+=fill;
            cnt++;
        }
        ans.push_back(temp);
        return ans;

    }
};