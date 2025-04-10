class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=0;
        bool charFound=false;
        for(int i=s.length()-1;i>=0;i--){
            if(charFound && s[i]==' ') return length;
            else if(s[i]!=' '){
                charFound=true;
                length++;
            }
        }
        return length;
    }
};