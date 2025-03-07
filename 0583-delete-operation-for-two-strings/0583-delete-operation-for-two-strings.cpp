class Solution {
public:
    vector<vector<int>> dp;

    int lcs(string& text1, string& text2, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) return dp[i][j] = 1 + lcs(text1, text2, i - 1, j - 1);
        else {
            return dp[i][j] = max(lcs(text1, text2, i - 1, j), lcs(text1, text2, i, j - 1));
        }
    }

    int minDistance(string& word1, string& word2) {
        int i = word1.size(), j = word2.size();
        dp.resize(i, vector<int>(j, -1)); // Initialize dp here
        int lcss = lcs(word1, word2, i - 1, j - 1); // Only call lcs once.
        return (word1.size() - lcss + word2.size() - lcss);
    }
};