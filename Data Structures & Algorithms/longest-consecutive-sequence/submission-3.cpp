class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //use of HashSet
        int result = 0;
        unordered_set<int> store(nums.begin(), nums.end());

        for(auto num : store){
            if(store.find(num-1) == store.end()){
                int length = 1;
                while(store.find(num+length) != store.end())
                    length++;
                
                result = max(result, length);
            }
        }
        return result;
    }
};
