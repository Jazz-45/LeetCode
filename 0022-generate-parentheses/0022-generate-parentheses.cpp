class Solution {
public:
    vector<string> ans;

    void backtrack(string &cur, int openRem, int closeRem) {
        // when we’ve placed all 2*n chars, record
        if (openRem == 0 && closeRem == 0) {
            ans.push_back(cur);
            return;
        }
        // we can place '(' so long as we have some left
        if (openRem > 0) {
            cur.push_back('(');
            backtrack(cur, openRem - 1, closeRem);
            cur.pop_back();
        }
        // we can place ')' only if it won’t unbalance
        if (closeRem > openRem) {
            cur.push_back(')');
            backtrack(cur, openRem, closeRem - 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string cur;
        backtrack(cur, n, n);
        return ans;
    }
};
