class Solution {
public:
    vector<vector<int>> result;

    void twoSum(vector<int>& nums, int target, int i, int j){
        while(i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else{   //found sum == target
                //remove duplicates
                while(i < j and nums[i] == nums[i+1]) i++;
                while(i < j and nums[j] == nums[j-1]) j--;

                // store ans
                result.push_back({-target, nums[i], nums[j]});
               
                // when ans found we have to move from both ends(i, j)
                i++; 
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        // n2+n3 = -n1
        // [-4, -1, -1, 0, 1, 2]
            //  n1   n2       n3
            //  n1     n2 n3

        int n = nums.size();
        if(n < 3){
            return {};
        }
        result.clear();

        // 1. sort nums- to gather duplicate side by side
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++){
            //if n1 has duplicates move forward
            if(i > 0 and nums[i] == nums[i-1]){
                continue;
            }
            // n2+n3 = -n1
            int n1 = nums[i];
            int target = -n1;

            twoSum(nums, target, i+1,n-1);
        }
        return result;
    }
};
