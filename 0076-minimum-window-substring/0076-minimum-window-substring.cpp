class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();

        if(t.length()>n) return "";

        unordered_map<char,int> m;

        for(char &ch : t) m[ch]++;

        int requiredCount=t.length();
        int i=0,j=0;

        int minWindowSize=INT_MAX;
        int start_i=0;

        while(j<n){
            char ch=s[j];

            // Count--;
            
            if(m[ch]>0){
                requiredCount--;
            }

            m[ch]--;

            while(requiredCount==0){
                int currWindowSize=j-i+1;

                if(currWindowSize<minWindowSize){
                    minWindowSize=currWindowSize;
                    start_i=i;
                }

                m[s[i]]++;

                if(m[s[i]]>0){
                    requiredCount++;
                }

                i++;
            }

            j++;
        }

        return (minWindowSize==INT_MAX) ? "" : s.substr(start_i,minWindowSize); 

    }
};