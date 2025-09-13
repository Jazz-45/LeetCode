class Solution {
public:
    int maxFreqSum(string s) {
        int crr[26]={0};
        for(char ch: s) crr[ch-'a']++;

        int maxV=0,maxC=0;
        for(int i=0;i<26;i++){
            char ch='a'+i;
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') maxV=max(maxV,crr[i]);
            else maxC=max(maxC,crr[i]);
        }
        return maxC+maxV;
    }
};