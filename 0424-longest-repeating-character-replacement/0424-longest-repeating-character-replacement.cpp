class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();

        vector<int> hash(26,0);
        
        int i=0,j=0;
        int maxLen=0;
        int maxFreq=0;
        while(j<n){
            hash[s[j]-'A']++;
            maxFreq=max(maxFreq,hash[s[j]-'A']);
            while((j-i+1)-maxFreq>k){
                hash[s[i]-'A']--;
                i++;
            }

            if((j-i+1)-maxFreq<=k) maxLen=max(maxLen,(j-i+1));
            j++;
        }
        return maxLen;
    }
};