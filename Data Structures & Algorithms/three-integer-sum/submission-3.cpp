class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        /*
            nums[i] + nums[j] + nums[k] == 0
            -(nums[i]) = nums[j] + nums[k]
        */
        //loop for i
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1] ) {
                continue;   //duplicate element ..skip
            }
            int j = i + 1;
            int k = nums.size()-1;

            while(j < k){
                int target = -(nums[i]);
                if(nums[j] + nums[k] < target)
                    j++;
                else if(nums[j] + nums[k] > target)
                    k--;
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};
