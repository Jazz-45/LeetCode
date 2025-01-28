class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        int minRabbits = 0;

        for (int answer : answers) {
            if (answer == 0) {
                // If a rabbit claims no other rabbits of the same type, count it directly
                minRabbits++;
            } else {
                // Check if there's space left in an existing group
                if (m[answer] > 0) {
                    m[answer]--; // Decrement the available slots for this group
                } else {
                    // Start a new group
                    minRabbits += answer + 1; // Add the size of the new group
                    m[answer] = answer; // Set available slots for this group
                }
            }
        }

        return minRabbits;
    }
};
