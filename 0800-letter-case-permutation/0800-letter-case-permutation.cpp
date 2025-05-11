class Solution {
public:
    vector<string> ans;

    bool isChar(char ch){
        if(isdigit(ch)) return false;
        return true;
    }

    void solve(string s,int idx,string& str){
        if(idx==s.length()){
            ans.push_back(str);
            return;
        }

        if(isChar(s[idx])==false){
            str+=s[idx];
            solve(s,idx+1,str);
            str.pop_back();
        }else{
            char lower=tolower(s[idx]);
            str+=lower;
            solve(s,idx+1,str);
            str.pop_back();
            char upper=toupper(s[idx]);
            str+=upper;
            solve(s,idx+1,str);
            str.pop_back();
        }
    }

    vector<string> letterCasePermutation(string s) {
        ans.clear();
        
        string str="";
        solve(s,0,str);
        
        return ans;
    }
};