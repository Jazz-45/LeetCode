class Solution {
public:
    string largestGoodInteger(string num) {
        int maxGood = -1;
        string finalAns;

        int n = num.length();
        for (int i = 0; i <= n - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string ans = string(3, num[i]);
                int x = stoi(ans);
                if (x > maxGood) {
                    finalAns = ans;
                    maxGood = x;
                }
            }
        }

        return (maxGood == -1) ? "" : finalAns;
    }
};
