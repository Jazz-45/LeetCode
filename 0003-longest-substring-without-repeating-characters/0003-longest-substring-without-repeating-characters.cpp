class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        unordered_set<char> s;
        int l = 0, r = 0;
        int maxi = 0;

        while (r < n) {
            if (s.find(str[r]) == s.end()) {
                s.insert(str[r]);
                maxi = max(maxi, (int)s.size());
                r++;
            } else {
                s.erase(str[l]);
                l++;
            }
        }
        return maxi;
    }
};
