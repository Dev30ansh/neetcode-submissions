class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int diff = -1;
        unordered_map<int, int> m;

        for(int i = 0; i< nums.size(); i++){
            m[nums[i]] = i;
        }

        for(int i = 0; i< nums.size(); i++){
            diff = target - nums[i];
            if(m.count(diff) && m[diff] != i){
                return {i, m[diff]};
            }
        }
    
    return {};
    }
};
