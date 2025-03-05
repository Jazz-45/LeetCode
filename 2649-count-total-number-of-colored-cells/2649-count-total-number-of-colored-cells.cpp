class Solution {
public:
    long long coloredCells(int n) {
        return 1LL + 4LL * (n - 1) + 4LL * (((long long)n - 1) * ((long long)n - 2) / 2);
    }
};
