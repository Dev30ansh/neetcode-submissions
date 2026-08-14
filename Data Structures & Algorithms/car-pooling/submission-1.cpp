class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Approach 2 : using difference array 
        int diff[1001] = {0};    // array size = 1001 and  all initialized with 0

        for(auto & trip : trips){
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            diff[start] += count;
            diff[end]   -= count;
        }

        int passangerSum = 0;

        for(int i = 0; i < 1001; i++){
            passangerSum += diff[i];

            if(passangerSum > capacity)
                return false;
        }
        
        return true;
    }
};