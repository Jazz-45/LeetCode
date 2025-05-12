class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> m;
        for (int x : digits) m[x]++;

        vector<int> ans;
        vector<int> freq(10, 0);

        for (int i = 100; i <= 999; i += 2) {
            int temp = i;
            fill(freq.begin(), freq.end(), 0); // Reset freq for each number

            // Count digits of i
            int t = temp;
            while (t) {
                freq[t % 10]++;
                t /= 10;
            }

            // Check if number can be formed
            bool flag = true;
            for (int d = 0; d <= 9; d++) {
                if (freq[d] > m[d]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(i);
        }

        return ans;
    }
};
