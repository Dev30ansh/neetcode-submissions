class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {


        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());


        for (int i = 0; i < (int)nums.size() - 2; i++) {    //loop for num[i]
            
            if (i > 0 && nums[i] == nums[i - 1]) 
                continue;

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {     //loop for num[j], num[k]
                int target = (-nums[i]);
                if ((nums[j] + nums[k]) < target) {
                    j++;
                } 
                else if ((nums[j] + nums[k]) > target) {
                    k--;
                } 
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
// skip duplicate values so you don’t add the same triplet more than once.
                    while (j < k && nums[j] == nums[j - 1]) 
                        j++;
                    while (j < k && nums[k] == nums[k + 1]) 
                        k--;
                    
                }
            }
        }
        
        return ans;
    }
};
