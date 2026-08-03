class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<int> &sides, int sideLen, int idx) {
        // Base case: all matchsticks have been used
        if (idx == matchsticks.size()) {
            return true;
        }
        
        // Try to place the current matchstick on each of the 4 sides
        for (int i = 0; i < 4; i++) {

            // Check if placing this stick on side i would exceed the target side length
            if (sides[i] + matchsticks[idx] <= sideLen) {
                // do : place stick on this side
                sides[i] += matchsticks[idx];
                
                // Explore: recursively place the next matchstick
                if (solve(matchsticks, sides, sideLen, idx + 1))
                    return true;
                
                // Undo: backtrack and remove the stick from this side
                sides[i] -= matchsticks[idx];
            }
            
            // If this side is still 0, it means we tried an empty side.
            if (sides[i] == 0)
                break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        // Calculate total length of all matchsticks
        int totalLength = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        // If total length is not divisible by 4, we cannot form a square
        if (totalLength % 4 != 0) {
            return false;
        }
        int sideLen = totalLength / 4;

        // Store current lengths of the 4 sides = 0
        vector<int> sides(4, 0);

        // Sort descending so we place larger sticks first
        // This helps prune invalid paths earlier
        sort(matchsticks.rbegin(), matchsticks.rend());

        // Start backtracking from the first matchstick
        return solve(matchsticks, sides, sideLen, 0);
    }
};