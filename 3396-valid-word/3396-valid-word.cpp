class Solution {
public:
    bool isValid(string word) {
        int n=word.length();
        if(n<3) return false;

        bool vowel=false,consonant=false;
        for(int i=0;i<n;i++){
            if(isalpha(word[i])==0 && isdigit(word[i])==0) return false;
            if(isalpha(word[i])){
                char ch=word[i];
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='I' || ch=='O' || ch=='U' || ch=='E') vowel=true;
                else consonant=true;
            }
        }

        return vowel && consonant;
    }
};