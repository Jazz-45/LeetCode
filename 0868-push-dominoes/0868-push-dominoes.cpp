class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.size();
        vector<int> indexes(N + 2);
        vector<char> symbols(N + 2);
        int len = 1;

        indexes[0] = -1;
        symbols[0] = 'L';

        for (int i = 0; i < N; ++i) {
            if (dominoes[i] != '.') {
                indexes[len] = i;
                symbols[len++] = dominoes[i];
            }
        }

        indexes[len] = N;
        symbols[len++] = 'R';

        vector<char> ans(dominoes.begin(), dominoes.end());

        for (int index = 0; index < len - 1; ++index) {
            int i = indexes[index], j = indexes[index + 1];
            char x = symbols[index], y = symbols[index + 1];

            if (x == y) {
                for (int k = i + 1; k < j; ++k)
                    ans[k] = x;
            } else if (x == 'R' && y == 'L') {
                for (int k = i + 1; k < j; ++k) {
                    if (k - i == j - k)
                        ans[k] = '.';
                    else if (k - i < j - k)
                        ans[k] = 'R';
                    else
                        ans[k] = 'L';
                }
            }
        }

        return string(ans.begin(), ans.end());
    }
};
