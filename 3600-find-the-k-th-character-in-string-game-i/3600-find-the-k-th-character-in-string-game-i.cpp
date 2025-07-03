class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while ((int)word.size() < k) {
            int length = word.size();
            for (int i = 0; i < length; i++) {
                if (word[i] == 'z') word += 'a';
                else word += word[i] + 1;
            }
        }
        return word[k - 1];
    }
};
