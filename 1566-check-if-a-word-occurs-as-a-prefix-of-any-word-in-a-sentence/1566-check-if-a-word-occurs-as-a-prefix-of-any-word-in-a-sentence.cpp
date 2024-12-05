class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.size();
        int m = searchWord.size();
        int count=1;
        for(int i=0;i<n;){
            if(sentence[i] == ' '){
                count++;
                i++;
            }
            else{
                int k = i;
                int j = 0;
                while(j < m && k < n && sentence[k] == searchWord[j]) {
                    k++;
                    j++;
                }
                if(j == m ) return count;
                while(i<n && sentence[i] != ' ') i++;
            }
        }
        return -1;
    }
};