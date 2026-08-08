class Solution {
public:
    vector<vector<int>> result;

    void solve(int i, vector<int> &nums,vector<int> &temp, int target, int total){
        //base case- if total = target
        if(total == target){
            result.push_back(temp);
            return;
        }

        //base case 2- if i is out of bound or total exceeds target
        if(i >= nums.size() or total > target){
            return;
        }

        //include i
        temp.push_back(nums[i]);
        // pass i instead of i+1 to allow choosing the same number again
        solve(i, nums, temp, target, total + nums[i]);

        //exclude i
        temp.pop_back();
        solve(i+1, nums, temp, target, total);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        result.clear(); // Ensure result is clear for multiple test calls
        vector<int> temp;
                                //total sum
        solve(0, nums, temp, target, 0);
        return result;  
    }
};
