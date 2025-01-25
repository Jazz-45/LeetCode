class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> unlocked(n, false);
        unlocked[0] = true; // Start with room 0 unlocked

        queue<int> keys;
        keys.push(0); // Start with the key to room 0

        while (!keys.empty()) {
            int idx = keys.front();
            keys.pop();

            for (int key : rooms[idx]) {
                if (!unlocked[key]) { // Only process keys for locked rooms
                    unlocked[key] = true;
                    keys.push(key);
                }
            }
        }

        // Check if all rooms are unlocked
        for (bool isUnlocked : unlocked) {
            if (!isUnlocked) return false;
        }

        return true;
    }
};