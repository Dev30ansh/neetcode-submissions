class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Approach : Line Sweep Technique Concepts
        
        // maintain an ordered_map<int,int> for index : count_of_passangers
        map<int,int> events;

        for(auto& trip : trips){
            int count = trip[0];
            int start = trip[1];
            int end   = trip[2];

            events[start] += count;
            events[end]   -= count;
        }

        int passangerCount = 0;

        for(auto & event : events){
            passangerCount += event.second;

            if(passangerCount > capacity){
                return false;
            }
        }
        return true;
    }
};