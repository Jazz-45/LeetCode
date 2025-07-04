class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> basket;
        int i = 0, maxLen = 0;

        for (int j = 0; j < n; ++j) {
            basket[fruits[j]]++;

            // If we have more than 2 types of fruits, shrink the window
            while (basket.size() > 2) {
                basket[fruits[i]]--;
                if (basket[fruits[i]] == 0) {
                    basket.erase(fruits[i]);
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
