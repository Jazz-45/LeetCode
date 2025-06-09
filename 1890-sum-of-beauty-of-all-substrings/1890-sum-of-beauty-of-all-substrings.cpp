class Solution {
public:
    int beautySum(string s) {
        int ans = 0;

        for(int i=0;i<s.length();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.length();j++){
                char ch = s[j];
                freq[ch - 'a']++;
                int maxiFreq = 0;
                int miniFreq = INT_MAX;

                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        maxiFreq = max(maxiFreq,freq[k]);
                        miniFreq = min(miniFreq,freq[k]);
                    }
                }
                ans += (maxiFreq - miniFreq);
            }
        }
        return ans;
        
    }
};