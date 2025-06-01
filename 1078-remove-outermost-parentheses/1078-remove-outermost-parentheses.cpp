class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(s[i]);
            else if(st.size()==1){
                if(s[i]==')') st.pop();
                else{
                    st.push(s[i]);
                    ans+=s[i];
                }
            }
            else{
                if(s[i]==')') st.pop();
                else st.push(s[i]);
                ans+=s[i];
            }
        }
        return ans;
    }
};