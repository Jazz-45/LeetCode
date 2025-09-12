class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }

    bool doesAliceWin(string s) {
        int vowelCount=0;
        for(char ch: s){
            if(isVowel(ch)) vowelCount++;
        }

        if(vowelCount==0) return false;
        else return true;
    }
};