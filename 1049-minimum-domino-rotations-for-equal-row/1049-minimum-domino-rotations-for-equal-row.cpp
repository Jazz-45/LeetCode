class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        unordered_map<int,int> m;
        // Build frequency map, counting each face only once per domino
        for (int i = 0; i < n; i++) {
            if (tops[i] == bottoms[i]) {
                m[tops[i]]++;
            } else {
                m[tops[i]]++;
                m[bottoms[i]]++;
            }
        }

        // Find the candidate value 'ele' that appears on at least n faces
        int ele = -1;
        for (auto &it : m) {
            if (it.second >= n) {
                ele = it.first;
                break;
            }
        }
        if (ele == -1) return -1;

        // Compute rotations needed to make all tops == ele, or all bottoms == ele
        int toprot = 0, bottomrot = 0;
        for (int i = 0; i < n; i++) {
            // If neither side can show 'ele', impossible
            if (tops[i] != ele && bottoms[i] != ele)
                return -1;
            // If top isn't already 'ele', we'd rotate this domino to bring ele up
            if (tops[i] != ele)
                toprot++;
            // If bottom isn't already 'ele', we'd rotate this domino to bring ele down
            if (bottoms[i] != ele)
                bottomrot++;
        }

        return min(toprot, bottomrot);
    }
};
