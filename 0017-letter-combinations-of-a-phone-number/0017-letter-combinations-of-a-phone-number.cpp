class Solution {
public:
    unordered_map<char,string> m;
    vector<string> ans;

    void solve(string digits, int idx, string& str){
        if(idx==digits.length()){
            ans.push_back(str);
            return;
        }

        char ch=digits[idx];
        string seq=m[ch];
        for(int i=0;i<seq.size();i++){
            str+=seq[i];
            solve(digits,idx+1,str);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        // Initialising Map
        m.clear();
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";

        if(digits.length()==0) return ans;

        string str="";
        solve(digits,0,str);

        return ans;

    }
};