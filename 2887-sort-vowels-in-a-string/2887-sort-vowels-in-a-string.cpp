class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') or
               (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U');
    }

    string sortVowels(string s) {
        string vowels="";
        for(char ch: s){
            if(isVowel(ch)) vowels+=ch;
        }

        sort(vowels.begin(),vowels.end());

        int i=0;
        for(char& ch: s){
            if(isVowel(ch)) ch=vowels[i++];
        }

        return s;
    }
};