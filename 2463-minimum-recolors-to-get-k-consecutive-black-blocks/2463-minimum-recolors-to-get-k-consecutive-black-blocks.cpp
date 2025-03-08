class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int black = 0, white = 0;
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'B') black++;
            else white++;
        }
        int i = 0, j = k;
        int minWhite = white;
        while (j <= n) { // Changed condition
            minWhite = min(minWhite, white); // moved minWhite calculate before the shift
            if (j == n) break; // added break condition to stop out of bounds error.
            if (blocks[j] == 'B') black++;
            else white++;
            if (blocks[i] == 'B') black--;
            else white--;
            i++;
            j++;

        }
        return minWhite;
    }
};